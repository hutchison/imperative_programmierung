/* Aufgabe 6
 *
 * Fertigen Sie für Ihr Sortierverfahren aus Aufgabe 5 eine experimentelle
 * Statistik der Anzahl von Vertauschungsoperationen an, in Abhängigkeit von der
 * Feldgröße.
 *
 * Führen sie dazu für jede Feldgröße (Sie sollten zumindest alle Größen
 * zwischen 2 und 100 testen) mehrere (zum Beispiel 100) Sortierungsläufe durch,
 * wobei Sie das Feld jeweils mit Zufallszahlen initialisieren. Geben Sie
 * Mittelwert und Standardabweichung der Anzahl von Vertauschungen aus.
 *
 * Was für eine Art von Zusammenhang zwischen Feldgröße und Anzahl der
 * Vertauschungen vermuten Sie?
 */

// 15 Punkte

// Zusammenhang: 1/4(n^2 - n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_FIELDSIZE 100
#define MAX_SORTRUNS 100

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int sort(int a[], int n)
{
	int ist_unsortiert = 1;
	int i = 0;
	int vertauschungen = 0;

	while (ist_unsortiert) {
		ist_unsortiert = 0;

		for (i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				ist_unsortiert = 1;
				swap(&a[i], &a[i+1]);
				vertauschungen++;
			}
		}
	}

	return vertauschungen;
}

int main()
{
	int n = 0;	// Feldgröße
	int s = 0;	// Anzahl von Sortierungsläufen
	int i = 0;
	int* a = (int *)calloc(1, sizeof(int));
	int stat[MAX_FIELDSIZE+1][MAX_SORTRUNS];

	srand(time(NULL));

	// iteriere über die Feldgröße:
	for (n = 2; n <= MAX_FIELDSIZE; n++) {
		a = (int *)realloc(a, n * sizeof(int));

		// 100 Sortierungsläufe:
		for (s = 0; s < MAX_SORTRUNS; s++) {
			// initialisiere das Array mit Zufallszahlen:
			for (i = 0; i < n; i++) {
				a[i] = rand();
			}

			stat[n][s] = sort(a, n);
		}
	}

	int anzahl_vertauschungen = 0;
	float mittelwert = 0.0;
	float varianz = 0.0;

	for (n = 2; n <= MAX_FIELDSIZE; n++) {
		anzahl_vertauschungen = 0;
		mittelwert = 0.0;
		varianz = 0.0;

		printf("%d:", n);

		for (s = 0; s < MAX_SORTRUNS; s++) {
			anzahl_vertauschungen += stat[n][s];
		}
		mittelwert = (float)anzahl_vertauschungen / (float)MAX_SORTRUNS;
		printf("\t%.2f", mittelwert);

		for (s = 0; s < MAX_SORTRUNS; s++) {
			varianz += pow((mittelwert - (float)stat[n][s]), 2);
		}
		printf("\t  %.2f", sqrt(varianz / (float)MAX_SORTRUNS));
		putchar('\n');
	}

	free(a);

	return 0;
}
