/* Aufgabe 2
 *
 * Entwickeln Sie ein Programm, das Zeichenfolgen in einer Datei klassifiziert
 * und zählt: Worte sind Folgen von Buchstaben, Zahlen sind Folgen von Ziffern
 * und gemischte Sequenzen sind Folgen von Ziffern und Buchstaben.
 *
 * Ihr Programm muss auch die Zeichen zählen, die zu keiner der klassifizierten
 * Folgen gehört und es muss erkennen, ob eine Folge vom Dateiende beendet wird.
 */

// Aufgabe 2b) 2 Punkte
// Aufgabe 2c) 17 Punkte

// Es wurde die ctype.h nicht eingebunden


// isdigit(c) - gibt != 0 (true) zurück, wenn es sich bei c um eine dezimale
// Zahl handelt (0-9), ansonsten 0 als return
// isalpha(c) - gibt != 0 (true) zurück, wenn es sich bei c um einen Buchstaben
// handelt, ansonsten 0 als return

#include <stdio.h>

main() {
	int prec, c;
	int zeichen = 0, worte = 0, zahlen = 0, mix = 0, misc = 0;
	int istwort = 0, istzahl = 0;

	do {
		if ((c = getchar()) != EOF)
			prec = c;
		zeichen++;
		if (isdigit(c))
			istzahl = 1;
		else if (isalpha(c))
			istwort = 1;
		else {
			misc++;
			if (istzahl && istwort)
				mix++;
			else if (istzahl)
				zahlen++;
			else if (istwort)
				worte++;
			istzahl = 0; istwort = 0;
		}
	} while (c != EOF);
	// Zur Übersichtlichkeit als separate Funktionsaufrufe:
	printf("%d Zeichen\n", zeichen - 1); // -1 weil in der Beispielausgabe EOF nicht als sonst. Zeichen mitgezählt wird
	printf("%d Worte\n", worte);
	printf("%d Zahlen\n", zahlen);
	printf("%d gemischte Sequenzen\n", mix);
	printf("%d sonstige Zeichen.\n", misc - 1); // -1 weil in der Beispielausgabe EOF nicht als sonst. Zeichen mitgezählt wird
	if (prec != '\n')
		printf("Letzte Zeichenfolge unvollständig.\n");
}
