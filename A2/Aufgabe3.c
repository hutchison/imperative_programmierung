/* Aufgabe 3
 *
 * Schreiben Sie ein Programm, das seine Standardeingabe in die Standardausgabe
 * kopiert und dabei jedes Zeichen, das kein druckbares Zeichen und kein
 * „Whitespace“ ist, durch die Ausgabe „\c_1c_2c_3“ ersetzt. Hierbei ist
 * c_1c_2c_3 der Zeichencode des Zeichens, repräsentiert durch drei
 * Dezimalziffern. Wie behandeln Sie die Ausgabe des „\“, um eine eindeutige
 * Darstellung zu erhalten?
 *
 * Sie können die Testfunktionen isprint und isspace verwenden.
 */

// 9 Punkte
//
// Begründung:
// Damit der korrekte Zahlenwert ausgegebn wird, muss c vom Typ int sein, da
// getchar() einen Funktionswert vom Typ int liefert.

/* Ein in der Eingabe vorhandener Backslash wird mit "\" ersetzt.
 * Dadurch sollten die meisten Missverständnisse verhindert werden, da somit
 * z.B. folgende Übersetzungen statt finden:
 * Stringfolge \000 → "\"000
 * Nullzeichen      → \000
 * Es kann also anhand der Ausgabe eindeutig differenziert werden, was als
 * Stringfolge und was als Nullzeichen in der Eingabe vorhanden war.
 */

#include <stdio.h>
#include <ctype.h>

int main() {
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\\')
			printf("\"\\\"");
		else if (isprint(c) || isspace(c))
			putchar(c);
		else
			printf("\\%03d", c);
	}
}
