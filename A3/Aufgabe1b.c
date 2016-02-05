/* Aufgabe 1 (b)
 *
 * Finden Sie heraus, in welche Include-Datei es eine #define-Konstante gibt,
 * die die Zahl π = 3.141… als double-Zahl liefert.
 */

// 2 Punkte

#include <stdio.h>
#include <math.h>

main() {
	printf("%f\n", M_PI);
}
