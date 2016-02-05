/* Aufgabe 2
 *
 * Schreiben Sie ein Programm, das Text in „Pseudo-Englisch“ erzeugen kann. Dazu
 * gehen Sie folgendermaßen vor:
 * * Bauen Sie ein dreidimensionales Feld auf, das für jedes Zeichen c
 *   (Buchstaben sowie Leerzeichen, Komma, und Punkt) die bedingte
 *   Wahrscheinlichkeit beinhaltet, dass das Zeichen c auf die Zeichen a und b
 *   folgt.
 *   Diese Tabelle können Sie beispielsweise durch die Analyse des „Moby
 *   Dick“ erzeugen (vgl. Übungsblatt 8, Aufgabe 4).
 * * Entwickeln Sie ein Verfahren, mit dem Sie aus einem Vektor von Werten (v_1,
 *   … , v_n), für die Sie einen Vektor von Wahrscheinlichkeiten (p_1, … , p_n)
 *   gegeben haben, einen Wert v_i zufällig wählen können, so dass die
 *   Wahrscheinlichkeit, dass Sie v_i bekommen eben genau p_i entspricht. Sie
 *   können davon ausgehen, dass gilt
 *   	\sum_{i=1}^n p_i = 1
 * * Erzeugen Sie mit Hilfe des dreidimensionalen Feldes einen Zufallstext
 *   dadurch, dass Sie sich jeweils die beiden zuletzt generierten Zeichen a und
 *   b merken und dann ein neues Zeichen c zufällig wählen, wobei Sie die
 *   Wahrscheinlichkeit eines bestimmten Zeichens c gegeben die Vorgänger a und
 *   b aus dem Feld entnehmen. Um das erste Zeichen zu erzeugen können Sie
 *   annehmen dass die Vorgängerzeichen der Punkt und das Leerzeichen sind.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 29

char * relevant_chars = "abcdefghijklmnopqrstuvwxyz,. ";
int abs_frequency[N][N][N];
float rel_frequency[N][N][N];

int calc_index(int c)
{
	if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	} else if (c >= 'a' && c <= 'z') {
		return c - 'a';
	} else if (c == ',') {
		return 26;
	} else if (c == '.') {
		return 27;
	} else if (c == ' ') {
		return 28;
	} else {
		return -1;
	}
}

char lookup(int i, int upper)
{
	if (i >= 0 && i <= 25) {
		if (upper > 0) {
			return i + 'A';
		} else {
			return i + 'a';
		}
	} else if (i == 26) {
		return ',';
	} else if (i == 27) {
		return '.';
	} else if (i == 28) {
		return ' ';
	} else {
		return -1;
	}
}

void count_letter(int a, int b, int c)
{
	int i = calc_index(a);
	int j = calc_index(b);
	int k = calc_index(c);

	if (i >= 0 && j >= 0 && k >= 0) {
		abs_frequency[i][j][k] += 1;
	}
}

void calc_rel_frequencies()
{
	int i, j, k;
	// für die Lesbarkeit sind sum und n floats:
	float sum = 0.0;
	float n = 0.0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			sum = 0.0;

			for (k = 0; k < N; k++) {
				sum += (float)abs_frequency[i][j][k];
			}

			for (k = 0; k < N; k++) {
				n = (float)abs_frequency[i][j][k];
				rel_frequency[i][j][k] = n / sum;
			}
		}
	}
}

int choose(float rel_freqs[])
{
	float p = (float)rand() / (float)(RAND_MAX);
	float sum = 0.0;
	int i;

	for (i = 0; i < N; i++) {
		sum += rel_freqs[i];
		if (p <= sum) {
			return i;
		}
	}
	return 4; // chosen by fair dice roll
}

int main(void)
{
	srand(time(NULL));

	// Zuerst zählen wir alle Buchstaben:
	int a = getchar();
	int b = getchar();
	int c;

	while ((c = getchar()) != EOF) {
		count_letter(a, b, c);
		a = b;
		b = c;
	}

	// Aus den absoluten Häufigkeiten werden relative Häufigkeiten:
	calc_rel_frequencies();

	// Erzeuge 140 Zeichen Pseudo-Englisch.
	// Wir haben schließlich 2016 - da sind wir internetkompatibel.
	int i = 0;
	int end = 140;
	int index_dot = calc_index('.');
	int index_space = calc_index(' ');

	a = index_dot;
	b = index_space;

	for (i = 0; i < end; i++) {
		c = choose(rel_frequency[a][b]);
		// Am Satzanfang schreiben wir immerhin noch groß:
		if (a == index_dot && b == index_space) {
			putchar(lookup(c, 1));
		} else {
			putchar(lookup(c, 0));
		}
		a = b;
		b = c;
	}
	putchar('\n');

	return 0;
}
