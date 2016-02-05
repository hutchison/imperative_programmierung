/* Aufgabe 3
 *
 * Wie oft muss man im Durchschnitt ein Kartenspiel in die Luft werfen, bis es
 * sortiert zu Boden fällt? — Schreiben Sie ein Programm, um das
 * auszuprobieren. Ein Vektor der Länge N, der die Zahlen 1 bis N enthält, soll
 * so lange zufällig durchmischt werden, bis die Zahlen sortiert im Vektor
 * stehen. (Eine Zufallsdurchmischung eines Vektors können Sie beispielsweise
 * mit Hilfe des Fisher-Yates-Shuffle erzeugen.)
 *
 * Schätzen Sie die mittlere Anzahl von Zufallsdurchmischungen, die benötigt
 * werden, in dem Sie den Mittelwert von 1000 solcher Sortiervorgänge bestimmen.
 *
 * Geben Sie eine Tabelle der im Mittel benötigten Zufallsdurchmischungen für N
 * = 2 bis N = 10 an. Welchen Zusammenhang vermuten Sie?
 */

// 20 Punkte

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Messungen mit 1000 Durchläufen:
 * N	swaps/1000
 * 2	1.02
 * 3	5.14
 * 4	22.22
 * 5	117.12
 * 6	691.14
 * 7	5047.94
 * 8	38306.32
 * 9	343033.06
 * 10	3752593.31
 *
 * Vermutung: es werden ca. n! Zufallsvertauschungen benötigt.
 */

int is_sorted(int a[], int n)
{
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1]) {
			return 0;
		}
	}
	return 1;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void shuffle(int a[], int n)
{
	int j = 0;

	for (int i = n-1; i > 0; i--) {
		j = rand() % (i+1);
		swap(&a[i], &a[j]);
	}
}

long bogosort(int a[], int n)
{
	long swaps = 0;

	while (!is_sorted(a, n)) {
		shuffle(a, n);
		swaps++;
	}

	return swaps;
}

/* Initialisiert das Array (a[i] = i). */
void init(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}

void print_array(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}

/* Macht einen Testlauf mit runs Durchläufen. Bei jedem Durchlauf wird das
 * Array initialisiert, einmal durchmischt und dann mit bogosort() sortiert.
 * Dabei wird die Anzahl der Vertauschungen gezählt.
 *
 * Zurückgegeben wird das Verhältnis der Vertauschungen und der Durchläufe.
 */
double testrun(int a[], int n, int runs)
{
	long swaps = 0;
	for (int i = 0; i < runs; i++) {
		init(a, n);
		shuffle(a, n);
		swaps += bogosort(a, n);
	}
	return (double)swaps / (double)runs;
}

int main(int argc, char *argv[])
{
	int N = 2;	// Anzahl der Elemente
	int *a;		// das Array mit den Elementen
	long swaps = 0;
	double m = 0;	// Mittelwert der benötigten Vertauschungen

	srand(time(NULL));

	for (N = 2; N <= 10; N++) {
		a = (int *)calloc(N, sizeof(int));
		m = testrun(a, N, 1000);
		printf("%d\t%.2f\n", N, m);
	}

	return 0;
}
