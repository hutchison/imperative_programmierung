/* Aufgabe 1 (c)
 *
 * Schreiben Sie ein Programm, dass die Zahl π durch Monte-Carlo-Simulation
 * berechnet.
 *
 * Nutzen Sie dafür folgende Idee: wenn Sie eine große Zahl von zufälligen
 * Punkten im Einheitsquadrat wählen, ist im Mittel bei π/4 dieser Punkte der
 * Abstand vom Ursprung nicht größer als 1. (Für einen Punkt (x,y) erhalten Sie
 * den Abstand durch √(x^2 + y^2))
 *
 * Wie viele zufällige Punkte im Einheitsquadrat benötigt Ihr Rechner, um π auf
 * sieben Nachkommastellen genau zu bestimmen?
 */

// 10 Punkte
//
// Keine Ausgabe des angenährten Wertes zu PI.
// Kein Vergleich oder eine Kontrolle möglich, ob der Wert annähernd stimmt.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int gen = 7; // Pi auf gen Nachkommastellen genau bestimmen
	int anzahlges = 0, anzahlkl1 = 0;
	double abstand, pi, x, y;
	double chk_m_pi, chk_pi;

	double M_PI = 3.14159265;

	srand(time(NULL));

	do {
		anzahlges++;
		x = rand() * 1.0 / RAND_MAX;
		y = rand() * 1.0 / RAND_MAX;
		abstand = sqrt(pow(x, 2) + pow(y, 2));

		if (abstand <= 1)
			anzahlkl1++;

		pi = (double)anzahlkl1 / anzahlges * 4;

		// kürzt die Pi Werte auf die entsprechende Anzahl Nachkommastellen
		// nicht schön, aber funktioniert
		chk_m_pi = (int)(M_PI * pow(10, gen)) / (double)pow(10, gen);
		chk_pi = (int)(pi * pow(10, gen)) / (double)pow(10, gen);
	} while (chk_m_pi != chk_pi);
	printf("Es wurden %d Punkte benötigt um Pi auf %d Stellen genau zu bestimmen.\n", anzahlges, gen);
}
