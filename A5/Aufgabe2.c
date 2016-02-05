/* Aufgabe 2
 *
 * Schreiben Sie ein Programm, das Zeilen von der Standardeingabe liest und für
 * jede Zeile die Zeichen in umgekehrter Reihenfolge ausgibt (ohne dass Sie
 * rewind verwenden).
 */

// 10 Punkte

#include <stdio.h>
//#include <unistd.h> // je nach Umgebung möglicherweise für isatty() nötig

int reverse() {
	int c, d;

	c = getchar();
	if (c != '\n' && c != EOF) {
		d = reverse();
		putchar(c);
		return d; // mit dem d bringen wir das EOF zur ersten Instanz zurück, spart später 1 Schleifendurchlauf :)
	} else
		return c;
}

int main() {
	int c;

	do {
		c = reverse();
		putchar('\n');
		// c = EOF, wenn stdin per Terminal eingegebener Text ist:
		if (isatty(_fileno(stdin))) // ist true wenn stdin mit dem Terminal verbunden ist // fileno() funktioniert nicht, _fileno schon
			c = EOF;
	} while (c != EOF);
}
