/* Aufgabe 1
 *
 * Schreiben Sie ein Programm, das den Wert der Konstanten EOF ausgibt (und
 * geben Sie das Ergebnis an).
 */

// 3 Punkte

/* Unter Mac OS X und Linux hat EOF den Wert -1. */

#include <stdio.h>

int main() {
	printf("EOF: %d\n", EOF);
}
