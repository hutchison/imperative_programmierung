/* Aufgabe 3
 *
 * Schreiben Sie ein Programm, das Zeilen von der Standardeingabe liest und für
 * jede Zeile die Zeichen in umgekehrter Reihenfolge ausgibt - ohne dass Sie ein
 * Feld benutzen.
 */

// Danke für den Hinweis, werde die Punkte korrigieren.
// Da ich kein MinGW nutze, was seine Eigenarten hat, sondern Pelles C und
// VS2015 mit C-Compiler, bekomme ich bei beiden eine Fehlermeldung.

// In dem folgenden Link ist beschrieben warum. Aber vermutlich kann ich den
// Fehler ausschalten, da fileno noch in der stdio.h vorhanden ist.
// https://msdn.microsoft.com/de-de/library/ms235401.aspx

// 8 Punkte

#include <stdio.h>
#include <unistd.h> // je nach Umgebung möglicherweise für isatty() nötig

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
		if (isatty(fileno(stdin)))
			c = EOF;
	} while (c != EOF);
}
