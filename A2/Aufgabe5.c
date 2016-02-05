/* Aufgabe 5
 *
 * Schreiben Sie ein Program, das die Zeilen und Spalten einer Datei vertauscht,
 * die auf der Standardeingabe eingelesen wird.
 *
 * Eingabezeilen, die kürzer als die maximale Länge sind, sollen in der Ausgabe
 * mit „.“-Zeichen aufgefüllt werden.
 *
 * Sinnvollerweise nutzen Sie in Ihrem Programm die Anweisung
 * rewind();
 * mit der Sie die Eingabedatei zurück auf den Anfang setzen können, falls Sie
 * die Standardeingabe aus einer Datei lesen.
 */

// 15 Punkte

# include <stdio.h>

main() {
	int i, j, k, c, nzeilen = 1, ns = 0, nspalten = 0;

	while ((c = getchar()) != EOF) { // Anzahl Zeilen, Spalten
		if (c == '\n') {
			ns = 0;
			nzeilen++;
		} else if (c != '\r') {
			ns++;
			if (ns > nspalten) {
				nspalten = ns;
			}
		}
	}

	for (i = 0; i < nspalten; i++) { // Spalten
		rewind(stdin);
		for (j = 0; j < nzeilen; j++) { // Zeilen
			for (k = 0; k <= i; k++) { // Cursor zur aktuellen Spalte
				c = getchar();
				if (c == '\n' || c == EOF) // wenn Zeilenende vor Anzahl Spalten, dann
					break;
			}
			if (c == '\n' || c == '\r' || c == EOF)
				putchar('.'); // Punkt einfügen
			else
				putchar(c);

			while (c != '\n' && c != EOF) // skip zur nächsten Zeile
				c = getchar();
		}
		putchar('\n');
	}
}
