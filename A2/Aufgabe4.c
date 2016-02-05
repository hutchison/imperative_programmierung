/* Aufgabe 4
 *
 * Schreiben Sie ein Programm, das eine Eingabedatei einliest und jedes Wort auf
 * einer eigenen Zeile ausgibt, wobei zusätzlich Zeilennummer und Wortnummer mit
 * ausgegebn werden.
 */

// 10 Punkte

# include <stdio.h>
# define IN 1  // inside a word
# define OUT 0 // outside a word

int main() {
	int c, nl = 1, nw = 0, state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			nl++;
			nw = 0;
		}
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else {
			if (state == OUT) {
				state = IN;
				nw++;
				printf("\n%d.%d ", nl, nw);
			}
			putchar(c);
		}
	}
}
