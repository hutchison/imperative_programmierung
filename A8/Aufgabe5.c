/* Aufgabe 5
 *
 * Sortieren. Entwickeln Sie eine Funktion zum Sortieren eines Feldes von Zahlen
 * mit Hilfe der Funktion swap aus der Vorlesung.
 *
 * Die Idee ist einfach:
 * * Wenn zwei benachbarte Zahlen im Feld in der falschen Reihenfolge sind, dann
 *   werden diese vertauscht.
 * * Dies machen sie so lange, bis keine Vertauschungen mehr erforderlich sind.
 */

// 15 Punkte

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

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
	int* a = (int *)calloc(1, sizeof(int));
	int n = 0;
	int i = 0;
	int vertauschungen = 0;

	while (scanf("%d\n", &a[n]) > 0) {
		n++;
		a = (int *)realloc(a, (n+1)*sizeof(int));
	}

	vertauschungen = sort(a, n);

	for (i = 0; i < n; i++) {
		printf("%d: %d\n", i+1, a[i]);
	}
	printf("Vertauschungen: %d\n", vertauschungen);

	free(a);
	return 0;
}
