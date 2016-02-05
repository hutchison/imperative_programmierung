/* Aufgabe 5
 *
 * Sinusfunktion.
 *
 * Schreiben Sie ein Programm, das den Sinus eines double-Wertes mit Hilfe
 * folgender Reihenentwicklung bestimmt:
 *
 * sin(x) = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n+1}}{(2n+1)!}
 *
 * Der Eingabewert soll dabei in Grad angegeben werden.
 *
 * Nutzen Sie das Programm, um eine Tabelle der Sinuswerte von 0° bis 720° in
 * 15°-Schritten zu erstellen.
 *
 * Beachten Sie:
 * 	* Die Reihenentwicklung erwartet, dass x in Bogenmaß angegeben wird.
 * 	* Natürlich können Sie die Reihenentwicklung nicht bis ∞ laufen lassen -
 * 	überlegen Sie sich ein sinnvolles Abbruchkriterium.
 */

//----------------------------------------------------
// 9 Punkte
//----------------------------------------------------
// Begründung:
// Der Wertebereich der Variablen "nenner" wirde bei zu vielen
// Schleifendurchgängen überschritten und es kommt zu eine Teilung durch 0.
// Entweder 1.E-x wobei x<11 um die Anzahl der Schleifendurchgänge zu verringern
// oder einen Typ mit größeren Werteberich wählen, z.B. double
//----------------------------------------------------

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double degree_to_rad(double r)
{
	return r*M_PI/180.0;
}

double sinus(double x)
{
	// normiere x auf [0, 360)
	x = fmod(x, 360.0);

	if (x > 90.0) {
		if (x > 180.0) {
			// aufmalen und scharf hinsehen:
			return -sinus(x - 180.0);
		} else {
			// Rückführung auf spitze Winkel:
			return sinus(180.0 - x);
		}
	}

	double x_rad = degree_to_rad(x);
	double x_rad_neu = x_rad;

	// Vorzeichen:
	int vz = 1;
	int n = 1;
	unsigned long nenner = 1;

	double sinx_alt = 0.0;
	// erstes Reihenglied:
	double sinx = vz * x_rad / nenner;

	// Reihenentwicklung bis die Unterschiede zwischen den Gliedern klein
	// genug sind:
	while (fabs(sinx - sinx_alt) > 1.0E-11) {
		vz = -1 * vz;

		nenner = nenner * (n+1) * (n+2); // Wertebereich von nenner wird bei zu viele Schleifendurchgängen überschritten
		n += 2;

		x_rad_neu = x_rad_neu * x_rad * x_rad;

		sinx_alt = sinx;
		sinx += vz * x_rad_neu / nenner;
	}

	return sinx;
}

int main(int argc, char *argv[])
{
	printf("   α\t|  sin(α)\n");
	printf("--------|--------------\n");

	for (double x = 0.0; x <= 720.0; x += 15.0) {
		printf("  %3.0f°\t| % 1.10f\n", x, sinus(x));
	}

	return 0;
}
