/* Aufgabe 3
 *
 * Schreiben Sie ein Programm, das eine Zahl einliest und dafür die Zerlegung in
 * Primfaktoren ausgibt. Ihr Programm soll beispielsweise für die Eingabe 1023
 * die Ausgabe 1 * 3 * 11 * 31 erzeugen, für die Eingabe 1024 die Ausgabe
 * 1 * 2^10 und für die Eingabe 13500 die Ausgabe 1 * 2^2 * 3^3 * 5^3.
 */

// 20 Punkte

# include <stdio.h>

int main() {
	int zahl, i, count = 1, teiler, preteiler = 1;

	printf("Zahl: ");
	scanf("%d", &zahl);

	do {
		// kleinsten Teiler finden:
		for (i = 2; i <= zahl; i++)
			if (zahl % i == 0) {
				teiler = i;
				break;
			}

		if (teiler != zahl) {
			if (teiler == preteiler)
				count++;	// Exponent +1
			else {
				if (count == 1)
					printf("%d * ", preteiler);
				else
					printf("%d^%d * ", preteiler, count);
				count = 1;	// Exponent zurücksetzen
			}
			zahl /= teiler;
			preteiler = teiler;
			teiler = 1;
		} else {
			if (count == 1)
				printf("%d * %d", preteiler, teiler);
			else
				printf("%d^%d", teiler, count + 1);
		}
	} while (teiler != zahl);
	printf("\n");
}
