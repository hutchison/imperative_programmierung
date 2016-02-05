/* Aufgabe 3
 *
 * Schreiben Sie ein Programm, das eine positive ganze Zahl in das binäre
 * Zahlensystem übersetzt. Dabei dürfen Sie die Binärstellen in umgedrehter
 * Reihenfolge ausgaben (d.h. niederwertigste Stelle zuerst), so dass Sie etwa
 * für die Zahl $13_{10}$ die Ausgabe $1011_2$ erhalten (in normaler Richtung
 * wäre die Ausgabe $1101_2$).
 */

//---------------------------------------------------
// 10 Punkte
//---------------------------------------------------

#include <stdio.h>

main(){
	int zahl = 0;

	printf("Zahl: ");
	scanf("%i", &zahl);
	if (zahl < 0)
		printf("Bitte nur positive ganze Zahlen eingeben");
	else
		do {
			printf("%d", zahl % 2);
			zahl /= 2;
		} while(zahl > 0);
	printf("\n");
}
