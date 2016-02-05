/* Aufgabe 2
 *
 * … und erweitern Sie auch den Codeknacker entsprechend.
 */

// 10 Punkte

// Hinweis: Ein zusätzliche Ausgabe in dem der codierte Text steht wäre
// hilfreich.  So sieht es im ersten Moment aus, als ob der eingegeben Text
// einfach wieder ausgegeben wird.

#include <stdio.h>
#include <math.h>

#define MAX 100
#define N 26

char imsg[MAX]; // plaintext
char omsg[MAX]; // ciphertext

void cipher(int shift) {
	int i, c;

	for (i = 0; imsg[i]; i++) {
		c = imsg[i];
		if (c >= 'a' && c <= 'z')
			omsg[i] = ((c - 'a') + shift) % N + 'a';
		else if (c >= 'A' && c <= 'Z')
			omsg[i] = ((c - 'A') + shift) % N + 'A';
		else
			omsg[i] = c;
	}
	omsg[i] = '\0';
}

void decipher() {
	double ofreq[N], nchar, chisq;
	double chmin = HUGE_VAL; // +oo, in math.h
	double efreq[N] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2,
		0.8, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4,
		0.2, 2.0, 0.1};
	int i, shift, smin;

	// reset data
	for (i = 0; i < N; i++)
		ofreq[i] = 0;
	// insert code for computing ofreq (Seite 103)
	for (nchar = 0.0, i = 0; imsg[i]; i++) {
		int c = imsg[i];
		if(c >= 'a' && c <= 'z') {
			++ofreq[c-'a'];
			++nchar;
		} else if (c >= 'A' && c <= 'Z') {
			++ofreq[c-'A'];
			++nchar;
		}
	}
	// convert to percentages
	for (nchar /= 100.0, i = 0; i < N; i++)
		ofreq[i] /= nchar;
	// insert code for computing smin (Seite 102 )
	for (shift = 0; shift < N; ++shift) {
		for (chisq = 0.0, i = 0; i < N; i++)
			chisq += pow(ofreq[(i + shift) % N] - efreq[i], 2.0) / efreq[i];
		if (chisq < chmin) {
			chmin = chisq;
			smin = shift;
		}
	}
	// decode
	cipher(N - smin);
}

int main() {
	fflush(stdin);
	printf("imsg: ");
	fgets(imsg, sizeof(imsg), stdin);
	decipher();
	printf("omsg: %s", omsg);
	return 0;
}
