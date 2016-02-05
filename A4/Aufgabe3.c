/* Aufgabe 3
 *
 * Erweitern Sie das Plotprogramm sin0.c (Skript Seite 61) so, dass es zwei
 * Kurven gleichzeitig zeichnen kann. Dabei soll die eine Kurve durch x und die
 * andere Kurve durch + dargestellt werden. Falls beide Zeichen auf der gleichen
 * Position landen, soll stattdessen das Zeichen * ausgegeben werden.
 *
 * Für das gleichzeitige Plotten von Cosinus (x) und Sinus (+) im Intervall
 * -180° bis 180° bei einer Schrittweite von 15° sollte sich dann folgende
 *  Ausgabe ergeben:

x         +
x      +
 x   +
   *
 +   x
+      x
+         x
+            x
 +             x
   +             x
     +             x
       +            x
          +         x
             +      x
               +   x
                 *
               x   +
             x      +
          x         +
       x            +
     x             +
   x             +
 x             +
x            +
x         +

 */

// 10 Punkte

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void indent_and_mark(int indent, char mark) {
/*
 * Schreibt `indent' Leerzeichen und dann den Buchstaben `mark' in die
 * Standardausgabe.
 */

	for (; indent > 0; --indent) {
		putchar(' ');
	}
	putchar(mark);
}

void cross_plus(int cross_indent, int plus_indent) {
/*
 * Schreibt ein 'x' nach `cross_indent' Leerzeichen und dann ein '+' nach
 * `plus_indent' Leerzeichen. Oder erst ein '+' und dann ein 'x' - je nachdem
 * was zuerst an der Reihe ist.
 * Bei Gleichheit wird ein '*' geschrieben.
 */

	if (cross_indent == plus_indent) {
		indent_and_mark(cross_indent, '*');
		putchar('\n');
	} else {
		if (cross_indent < plus_indent) {
			indent_and_mark(cross_indent, 'x');
			/*
			 * Hier müssen wir von `plus_indent' noch 1 mehr
			 * abziehen, weil wir gerade ein 'x' geschrieben haben:
			 */
			indent_and_mark(plus_indent - (cross_indent + 1), '+');
			putchar('\n');
		} else {
			indent_and_mark(plus_indent, '+');
			indent_and_mark(cross_indent - (plus_indent+ 1), 'x');
			putchar('\n');
		}
	}
}

int main(int argc, char *argv[])
{
	double x;
	for (x = -180.0; x <= 180.0; x+=15.0) {
		cross_plus(
			round(10 + 10*cos(x/180.0*M_PI)),
			round(10 + 10*sin(x/180.0*M_PI))
		);
	}

	return 0;
}
