/* Aufgabe 4
 *
 * Schreiben Sie ein rekursives Programm, das alle Permutationen von n Elementen
 * ausgibt. (D.h., alle möglichen unterschiedlichen Reihenfolgen der Elemente.)
 * Das Programm soll die Zahl n als Kommandozeilenargument akzeptieren (Sie
 * können die Methode hierfür von hanoi.c kopieren). Sie können davon ausgehen,
 * dass n nicht größer als 26 ist, so dass Sie die Elemente mit Buchstaben
 * bezeichnen können.
 *
 * Tipp: Heaps Algorithmus.
 */

// 12 Punkte

#include <stdio.h>
#include <stdlib.h>

int generate(int n, char A[], const int N, int p)
/*
 * Erzeugt die Permutationen nach Heap’s Algorithmus. N ist dabei die Länge von
 * A.
 *
 * Nebenbei zählen wir die Anzahl der Permutationen und geben sie am Ende
 * zurück. p ist dabei die Anzahl der schon ausgegebenen Permutationen.
 */
{
	int i = 0;
	int r = 0;
	char h;

	if (n == 1) {
		printf("%d: %s\n", p, A);
		return 1;
	} else {
		for (i = 0; i < n-1; ++i) {
			r += generate(n-1, A, N, r+p);
			if (n % 2 == 0) {
				// swap(A[i], A[n-1])
				h = A[i];
				A[i] = A[n-1];
				A[n-1] = h;
			} else {
				// swap(A[0], A[n-1])
				h = A[0];
				A[0] = A[n-1];
				A[n-1] = h;
			}
		}
		r += generate(n-1, A, N, r+p);
		return r;
	}
}

int main(int argc, char *argv[])
{
	int N;
	int p = 0;

	if (argc < 2 || (N = atoi(argv[1])) < 0) {
		printf("Usage: %s <number-of-elements>\n", argv[0]);
		return -1;
	} else {
		char A[N+1];
		for (int i = 0; i < N; ++i) {
			A[i] = 'A' + i;
		}
		A[N] = '\0';

		p = generate(N, A, N, 1);

		printf("%d permutations\n", p);
	}
	return 0;
}
