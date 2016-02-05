/* Aufgabe 4
 *
 * Schreiben Sie ein Programm, das die ersten 100 008 Primzahlen berechnet und
 * ausgibt. (Primzahl 1 ist die 2; Primzahl 100 008 ist die 1 299 827)
 * (Zum Nachkontrollieren siehe z. B.: http://primes.utm.edu/lists/small/100000.txt)
 *
 * Nutzen Sie Ihr Programm, um die 2 000 000te Primzahl zu berechnen. (Zum
 * Nachkontrollieren: das ist 32 452 843.)
 *
 * Wie lange läuft das Programm auf Ihrem Rechner?
 */

// 20 Punkte
//
// Anmerkung: die Zeitangaben mit 1 sek für 100008 Primzahlen mit Ausgabe finde
// ich sehr gering geschätzt
// habe ein Zeitabfrage eingebaut, bei mir benötigt das Programm für das
// Berechnen von 100008 Primzahlen mit Ausgabe auf meinem Rechner ca. 33sek.

#include <stdio.h>
#include <time.h>

int is_prime(int n)
/*
 * Testet `n' auf die Primzahleigenschaft.
 */
{
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	if ((n % 2) == 0 || (n % 3) == 0) return 0;

	for (int i = 5; i*i <= n; i += 6) {
		if ((n % i) == 0 || (n % (i+2) == 0)) {
			return 0;
		}
	}

	return 1;
}

void primzahlen_bis(int n)
/*
 * Gibt die ersten `n' Primzahlen aus.
 */
{
	int prim_count = 0;

	for (int i = 1; prim_count < n; i++) {
		if (is_prime(i)) {
			prim_count++;
			printf("#%d\t->\t%d\n", prim_count, i);
		}
	}
}

int main()
{
	clock_t pstart, pende;
	pstart = clock();
	// Je nach Teilaufgabe bitte auskommentieren:
	primzahlen_bis(100008);
	/*
	 * Dauer: das Unix-Programm 'time' liefert:
	 * 0,27s user 0,14s system 41% cpu 0,998 total
	 * Die Berechnung dauert demnach knapp eine Sekunde.
	 */

	//primzahlen_bis(2*1000*1000);
	/*
	 * Dauer: 'time' liefert:
	 * 17,89s user 3,57s system 73% cpu 29,054 total
	 * Die Berechnung dauert fast 30 Sekunden.
	 */

	pende=clock();
	printf("Laufzeit %5.2f s\n", (float) (pende-pstart)/CLOCKS_PER_SEC);

}
