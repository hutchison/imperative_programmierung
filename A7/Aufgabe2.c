/* Aufgabe 2
 *
 * Schreiben Sie ein Programm, das viel schneller arbeitet, als das Programm aus
 * Aufgabe (1). (Sie können sich zum Beispiel bereits berechnete Zahlen in einem
 * Feld merken.)
 */

// 5 Punkte

// Laufzeit: 0.04s

#include <stdio.h>
#include <time.h>

long long int results[51] = {0};

long long int fib(const int n) {
	if (n < 2)
		return n;
	else if (results[n] == 0)
		results[n] = fib(n - 1) + fib(n - 2);
	return results[n];
}

int main() {
	int i;
	clock_t pstart, pende;

	pstart = clock();
	for (i = 0; i <= 50; i++)
		printf("fib(%d) = %lld\n", i, fib(i));
	pende = clock();
	printf("Laufzeit: %.2f Sekunden\n", (double)(pende - pstart) / CLOCKS_PER_SEC);
	return 0;
}
