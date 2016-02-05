/* Aufgabe 1
 *
 * Das Programm zum Zählen von Zeilen aus der Vorlesung ignoriert eine
 * unvollständige letzte Zeile (d.h. eine Buchstabenfolge, die vor dem EOF nicht
 * mit einem Zeilenende \n abgeschlossen wird).
 *
 * Erweitern Sie das Programm so, dass
 * (1) die unvollständige Zeile (falls vorhanden) mitgezählt wird und
 * (2) in diesem Fall eine zusätzliche Meldung der Form „letzte Zeile
 *     unvollständig mit n Zeichen“ ausgeben wird.
 */

// 10 Punkte

#include <stdio.h>

main() {
	int c, count = 0, nl = 0;

	while ((c = getchar()) != EOF) {
		count++;
		if (c == '\n') {
			++nl;
			count = 0;
		}
	}
	if (count > 0) {
		++nl;
		printf("Letzte Zeile unvollständig mit %d Zeichen.\n", count);
	}
	printf("%d lines \n", nl);
}
