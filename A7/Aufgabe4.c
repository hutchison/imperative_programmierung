/* Aufgabe 4
 *
 * Schreiben Sie eine neue Version von fnord, die eine Schleife statt einer
 * Rekursion nutzt.
 */

// 5 Punkte

#include <stdio.h>

double fnord() {
	int c;
	double v = 0;

	c = getchar();
	while (c >= '0' && c <= '9') {
		v = v*10 + (c-'0');
		c = getchar();
	}
	return v;
}

int main() {
	printf("%f\n", fnord());
	return 0;
}
