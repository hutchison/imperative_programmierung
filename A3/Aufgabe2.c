/* Aufgabe 2
 *
 * Schreiben Sie ein Programm, das die längste Zeile einer Datei ausgibt. Was
 * für ein Problem haben Sie hierbei? Welche Lösung auf Basis der Mittel, die
 * Sie bisher in der Vorlesung gehört haben, schlagen Sie vor?
 */

// 8 Punkte
// Die Antwort in der PDF auf die Frage, was es hierbei für ein Problem geben
// könnte, ist nicht richtig.  Es ist ja nicht schlimm wenn nur die erste Zeile
// ausgegebn wird, wenn es zwei Zeilen gibt, die gleich lang sind.  Es gibt zwei
// Probleme die ein größeres Problem verursachen, wenn man nicht darauf achtet.

# include <stdio.h>

int main() {
	int c;
	int zmax = 0;		// Index der längsten Zeile
	int zeile = 0;		// Index der aktuellen Zeile
	int anzahl_zeilen = 0;
	int zlen = 0;		// Länge der längsten Zeile
	int zlencur = 0;	// Länge der aktuellen Zeile

	// längste Zeile und Anzahl der Zeilen ermitteln:
	do {
		c = getchar();
		if (c == '\n' || c == EOF) {
			if (zlen < zlencur) {
				zlen = zlencur;
				zmax = zeile;
			}
			zeile++;
			zlencur = 0;
		} else {
			zlencur++;
		}
	} while (c != EOF);
	rewind(stdin);

	anzahl_zeilen = zeile;
	int l[anzahl_zeilen];	// Längen der einzelnen Zeilen

	zeile = 0;
	zlencur = 0;

	// Längen der Zeilen ermitteln und abspeichern:
	do {
		c = getchar();
		if (c == '\n' || c == EOF) {
			l[zeile] = zlencur;
			zeile++;
			zlencur = 0;
		} else {
			zlencur++;
		}
	} while(c != EOF);
	rewind(stdin);

	// Zum Schluss durchlaufen wir nochmal Zeile für Zeile und wenn die
	// aktuelle Zeile von maximaler Länge ist, dann wird sie ausgegeben:
	for (zeile = 0; zeile < anzahl_zeilen; zeile++) {
		do {
			c = getchar();
			if (l[zeile] == zlen) {
			/* Sonderfall: was machen wir, wenn die längste
			 * Zeile die Länge 0 hat? Der Ästhetik halber sollten
			 * wir das überprüfen, weil sonst Quark (nämlich EOF)
			 * ausgegeben wird:
			 */
				if (zlen > 0) {
					putchar(c);
				} else {
					putchar('\n');
				}
			}
		} while(c != '\n' && c != EOF);
	}
}
