/* Aufgabe 6
 *
 * Fakultät, „beliebig“ genau. Schreiben Sie ein Programm, das ein iteratives
 * Verfahren zur Berechnung der Fakultät verwendet und dabei n! exakt
 * ausrechnet.
 *
 * Hinweis: Legen Sie zur Speicherung des aktuellen Wertes von n! ein int-Feld
 * an, bei dem jedes Feldelement zum Beispiel 5 Dezimalstellen von n! speichert
 * und verwenden Sie entsprechend das Verfahren der schriftlichen
 * Multiplikation.
 */

// 14 Punkte
//
// Ungültige Konvertierung von void* zu int*.
// Lösung: int* f = (int*) calloc(1,sizeof(int))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dezimalstellen(int n)
/*
 * Berechnet die Anzahl der Dezimalstellen von n. Es wird _nicht_ überprüft, ob
 * n < 0 ist! Das sollte uns aber auch nicht stören.
 */
{
	if (n == 0) {
		return 1;
	} else {
		return (int)floor(log10(n)) + 1;
	}
}

void print_nullen(int n)
/*
 * Gibt n Nullen ('0') aus.
 */
{
	for (int i = 0; i < n; ++i) {
		putchar('0');
	}
}

void fakultaet(int n)
/*
 * Berechnet n! und zwar für beliebig große n (naja, solange der RAM reicht).
 *
 * Dafür speichern wir das Ergebnis in einem Array (f), welches je nach Bedarf
 * vergrößert wird. Die einzelnen Elemente („Glieder“) von f enthalten max. 5
 * Stellen der Fakultät. f wird dabei „rückwärts“ aufgebaut: f[0] enthält die
 * letzten 5 Stellen, f[1] die vorletzten, …, f[l-1] enthält die ersten 5
 * Stellen. Beispielsweise ist:
 *
 * ┌─────┬─────┐
 * │ 123 │ 456 │
 * └─────┴─────┘
 *
 * = 123*100000^0 + 456*100000^1
 * = 45600123
 */
{
	int i = 1;
	int k = 0;
	int c = 0; // Übertrag (carry)
	const int BASE = 100000; // die Basis für die einzelnen Glieder
	const int E_BASE = dezimalstellen(BASE);
	// Initialisierung von f:
	int* f = calloc(1, sizeof(int));
	f[0] = 1;
	int l = 1; // Länge von f

	// Eigentliche Fakultätsberechnung:
	for (i = 1; i <= n; i++) {
		// Am Anfang jeder neuen Multiplikation ist c immer 0:
		c = 0;

		/*
		 * Wir multiplizieren jedes Glied von f mit i,
		 * addieren den letzten Übertrag,
		 * berechnen den neuen Übertrag
		 * und speichern die 5 Stellen ab:
		*/
		for (k = 0; k <= l-1; k++) {
			f[k] *= i;
			f[k] += c;
			c = f[k] / BASE;
			f[k] %= BASE;
		}

		/*
		 * Falls am Ende immer noch ein Übertrag zu addieren ist (also
		 * unser bisheriges Array zu klein ist), dann vergrößern wir f
		 * um 1:
		 */
		if (c > 0) {
			l++;
			f = (int *)realloc(f, l*sizeof(int));
			f[l-1] = c;
		}
	}

	// Die ersten 5 Stellen brauchen nicht mit Nullen aufgefüllt werden:
	printf("%d", f[l-1]);
	/*
	 * Danach wird f von hinten nach vorne (aus Sicht des Arrays) ausgeben.
	 * Falls das gespeicherte Glied weniger als 5 Stellen hat, wird es mit
	 * Nullen aufgefüllt.
	 */
	for (i = l-2; i >= 0; i--) {
		print_nullen((E_BASE-1)-dezimalstellen(f[i]));
		printf("%d", f[i]);
	}
	printf("\n");

	// Immer schön aufräumen:
	free(f);
}

int main(int argc, char *argv[])
{
	int n;

	if (argc < 2 || (n = atoi(argv[1])) < 0) {
		printf("Usage: %s <n>\n", argv[0]);
		return -1;
	} else {
		fakultaet(n);
	}

	return 0;
}
