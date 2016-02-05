/* Aufgabe 1
 *
 * Schreiben Sie ein Programm, das eine Datei einliest, die zeilenweise Einträge
 * der Form
 * 	Vorname Nachname Matrikelnummer Geburtsjahr
 * enthält, und diese in umgekehrter Reihenfolge im Format
 * 	Matrikelnummer Nachname Vorname Geburtsjahr
 * wieder ausgibt.
 *
 * So soll für eine Datei mit dem Inhalt
 * 	John Doe 210123456 1991
 * 	Fred Feuerstein 211987501 1992
 * 	Erika Mustermann 213092495 1996
 * die Ausgabe
 * 	213092495 Mustermann Erika 1996
 * 	211987501 Feuerstein Fred 1992
 * 	210123456 Doe John 1991
 * erfolgen.
 *
 * Sie benötigen für die Lösung dieser Aufgabe keine Arrays und keinen
 * dynamischen Speicher. Für die Speicherung eines Eintrags ist die Nutzung
 * einer struct sinnvoll. Sie können davon ausgehen, dass Name und Vorname
 * jeweils nicht länger als 20 Zeichen sind.
 */

// 15 Punkte

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 20

struct person {
	char vorname[N];
	char nachname[N];
	long matrikelnr;
	int geb_jahr;
};

/* Initialisiert eine person. */
struct person reset_person(struct person p)
{
	int i;
	for (i = 0; i < N; i++) {
		p.vorname[i] = '\0';
		p.nachname[i] = '\0';
	}
	p.matrikelnr = 0;
	p.geb_jahr = 0;

	return p;
}

void print_person(struct person p)
{
	printf("%ld %s %s %d\n",
		p.matrikelnr,
		p.nachname,
		p.vorname,
		p.geb_jahr
	);
}

void reverse_people()
{
	struct person p;
	int c;
	int i = 0;
	int spaces = 0;	// Anzahl eingelesener Leerzeichen
	int saved = 0;	// zeigt an, ob wir etwas gespeichert haben

	p = reset_person(p);

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			spaces++;
			i = 0;
		}
		/* Am Ende einer Zeile rufen wir reverse_people() rekursiv auf.
		 * So nutzen wir den Call-Stack, um die Zeilen in umgekehrter
		 * Reihenfolge auszugeben.
		 * */
		if (c == '\n') {
			reverse_people();
		}

		if (isalnum(c)) {
			saved = 1;
			if (spaces == 0) {
				p.vorname[i] = c;
				i++;
			} else if (spaces == 1) {
				p.nachname[i] = c;
				i++;
			} else if (spaces == 2) {
				p.matrikelnr = 10*p.matrikelnr + (c - '0');
			} else if (spaces == 3) {
				p.geb_jahr = 10*p.geb_jahr + (c - '0');
			}
		}
	}
	/* Wir geben die Person nur aus, wenn vorher etwas abgespeichert wurde.
	 * Ansonsten haben wir das Problem, dass bei (c == EOF) die "leere"
	 * Person ausgegeben wird.
	 */
	if (saved) {
		print_person(p);
	}
}

int main(int argc, char *argv[])
{
	reverse_people();
	return 0;
}
