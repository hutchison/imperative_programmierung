/* Aufgabe 1
 *
 * Die Fibonacci-Zahlen fib(i) sind wie folgt definiert:
 *
 * 	fib(0) = 0
 * 	fib(1) = 1
 * 	fib(n) = fib(n-1) + fib(n-2)
 *
 * Schreiben Sie auf dieser Basis ein rekursives Programm, das die ersten
 * Fibonacci-Zahlen für n = 0 … 50 ausgibt. (Sie müssen hier mit 64-bit Zahlen
 * arbeiten, das ist long int).
 *
 * Geben Sie an, wie lang ihr Programm läuft.
 */

// 5 Punkte

// Laufzeit: 212.58s

#include <stdio.h>
#include <time.h>

long long int fib(const int n) {
	if (n < 2)
		return n;
	else
		return (fib(n - 1) + fib(n - 2));
}

int main() {
	int i;
	clock_t pstart, pende;

	pstart = clock();
	for (i = 0; i <= 50; i++) {
		printf("fib(%d) = %lld\n", i, fib(i));
	}
	pende = clock();
	printf("Laufzeit: %.2f Sekunden\n", (double)(pende - pstart) / CLOCKS_PER_SEC);
	return 0;
}
