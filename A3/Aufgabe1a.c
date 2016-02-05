/* Aufgabe 1 (a)
 *
 * Finden Sie heraus, wie Sie in Ihrer C-Umgebung eine double-Zufallszahl
 * zwischen 0 und 1 erzeugen können.
 */

// 3 Punkte
//
// Ein kommentierter Quellcode um zu zeigen, dass ihr es verstanden habt, wäre
// gut.
// Diesen Quellcode findet man sehr einfach im Internet.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
	srand(time(NULL));
	printf("%f\n", rand() * 1.0 / RAND_MAX);
	printf("%f\n", rand() * 1.0 / RAND_MAX);
}
