/* Aufgabe 2
 *
 * Schreiben Sie ein Programm, das seine Standardeingabe in die Standausgabe
 * kopiert und dabei jede Folge von Leerzeichen und Tabulatorzeichen durch ein
 * einzelnes Leerzeichen ersetzt.
 */

// 10 Punkte

#include <stdio.h>

int main() {
	char c, prec = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t') {
			putchar(c);
			prec = c;
		} else if (prec != ' ') {
			putchar(' ');
			prec = ' ';
		}
	}
}
