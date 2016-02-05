/* Aufgabe 3
 *
 * Schreiben Sie ein Programm, das für jede Zeile der Standardeingabe prüft, ob
 * es sich dabei um ein Palindrom handelt; Zeilen, die Palindrome sind, sollen
 * ausgegeben werden.
 */

// 5 Punkte
// Sind mehrere Palindrome in einem Text enthalten, wird nur das letzte gefunden
// Palindrom ausgegeben.

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h> // je nach Umgebung möglicherweise für isatty() nötig

int count;
int *zeile;

int reverse() {
	int c, d, pos;

	c = getchar();
	if (c != '\n' && c != EOF) {
		pos = count;
		count++; // count ist global und wird somit mit jedem rekursiven Aufruf größer
		d = reverse();
		zeile[pos] = c;
		return d; // mit dem d bringen wir das EOF zur ersten Instanz zurück, spart später 1 Schleifendurchlauf :)
	} else {
		zeile = malloc((count) * sizeof(int)); // Größe des Array setzen
		return c;
	}
}

int main() {
	int c, i, palindrome;

	do {
		palindrome = 1;
		count = 0;
		c = reverse();
		for (i = 0; i < count; i++) // Array vorwärts und rückwärts vergleichen
			if (zeile[i] != zeile[count - i - 1])
				palindrome = 0;
		if (palindrome) { // bei Gleichheit ausgeben
			for (i = 0; i < count; i++)
				putchar(zeile[i]);
			putchar('\n');
		}
		// c = EOF, wenn stdin per Terminal eingegebener Text ist:
		if (isatty(fileno(stdin))) // ist true wenn stdin mit dem Terminal verbunden ist  // filno() funktioniert nicht, _fileno() schon.
			c = EOF;
	} while (c != EOF);
}
