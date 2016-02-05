/* Aufgabe 3
 *
 * Erweitern Sie den Chiffre zusätzlich so, dass man im Schlüsseltext nicht mehr
 * direkt erkennt, an welchen Positionen im Klartext welche Art von Zeichen
 * (Kleinbuchstabe, Großbuchstabe) stand.
 */

// 3 Punkte
// Bemerkung: Diese Verschlüsselung entspricht nicht der Aufgabestellung, es
// sollte der Code aus Aufgabe 1 erweitert werden, wo im verschlüsselten Text
// Groß- und Kleinschreibung keinen Hinweis liefert auf die Groß- und
// Kleinschreibung im Ursprungstext.
//
// Bsp. Aufgabe 1: normale Verschlüsselung mit einem Shift von 3
//	Hallo -> Kdoor
// Bsp. Aufgabe 3:
//	Hallo -> kDOoR

// Und kann diese Verschlüsselung auch wieder dechiffriert werden?

#include <stdio.h>

int caesar(int c, int key){
	if (c >= ' ' && c <= '~') {
		c = c-' ';
		c = (c+key) % ('~' - ' ' + 1);
		c = c+' ';
	}
	return c;
}

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		c = caesar(c, 20);
		putchar(c);
	}
	return 0;
}
