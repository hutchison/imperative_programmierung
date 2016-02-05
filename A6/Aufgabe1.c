/* Aufgabe 1
 *
 * Sei ggT(a,b) der größte gemeinsame Teiler von zwei positiven ganzen Zahlen a
 * und b. Für ggT gilt unter anderem:
 *
 * 	ggT(a, b) = ggT(b, a)
 * 	ggT(a, 0) = a
 * 	ggT(a, b) = ggT(b, a mod b) mit a ≥ b
 *
 * Erstellen Sie auf dieser Basis eine rekursive Funktion, die den größten
 * gemeinsamen Teiler zweier Zahlen berechnet.
 */

// 8 Punkte

#include <stdio.h>

int ggt(const int a, const int b)
{
	if (b == 0) {
		return a;
	} else {
		if(a >= b) {
			return ggt(b, a % b);
		} else {
			return ggt(b, a);
		}
	}
}

int main() {
	int a, b;

	printf("1. Zahl: ");
	scanf("%d", &a);
	printf("2. Zahl: ");
	scanf("%d", &b);
	printf("GGT: %d\n", ggt(a, b));

	return 0;
}
