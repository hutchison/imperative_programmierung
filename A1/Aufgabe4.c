/* Aufgabe 4
 *
 * Schreiben Sie ein Programm, das eine Folge von nicht-negativen Zahlen von der
 * Standardeingabe einliest und die größte dieser Zahlen ausgibt.
 *
 * Das Ende der Zahlenfolge wird durch die Eingabe einer negativen ganzen Zahl
 * signalisiert.
 *
 * Benutzen Sie *nicht* die if-Anweisung, den ternären ?-Operator oder
 * irgendeine max bzw. min-Funktion.
 */

//----------------------------------------------------
// 10 Punkte
//----------------------------------------------------

#include <stdio.h>

main(){
	int max  = 0;
	int zahl = 0;
	int i    = 0;

	while(zahl >= 0) {
		i++;
		printf("%i. Zahl: ", i);
		scanf("%i", &zahl);
		while(max < zahl) {
			max = zahl;
		}
	}
	printf("Max: %i", max);
}
