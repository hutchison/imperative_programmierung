/* Aufgabe 2
 *
 * Schreiben Sie ein Programm, das den Wert von 3^7 berechnet, wobei Sie nur die
 * Addition oder Subtraktion der Zahl eins (Ausdrücke wie x+1 und x-1) benutzen
 * dürfen. Sonstige arithmetische Ausdrücke sind nicht erlaubt. Nutzen Sie
 * folgende rekursive Denitionen:
 *
 * 	  add(x, 0) = x
 * 	add(x, y+1) = add(x+1, y)
 * 	  mlt(x, 1) = x
 * 	mlt(x, y+1) = add(mlt(x, y), x)
 * 	  pwr(x, 0) = 1
 * 	pwr(x, y+1) = mlt(pwr(x, y), x)
 */

// 8 Punkte

#include <stdio.h>

int add(const int a, const int b) {
	if (b == 0)
		return a;
	else
		return add(a + 1, b - 1);
}

int mlt(const int a, const int b) {
	if (b == 1)
		return a;
	else
		return add(mlt(a, b - 1), a);
}

int pwr(const int a, const int b) {
	if (b == 0)
		return 1;
	else
		return mlt(pwr(a, b - 1), a);
}

int main() {
	printf("3^7: %d\n", pwr(3, 7));

	return 0;
}
