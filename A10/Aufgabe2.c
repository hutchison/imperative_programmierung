/* Aufgabe 2
 *
 * Taschenrechner mit Variablen: Erweitern Sie Ihr Programm aus Aufgabe 5 von
 * Aufgabenblatt 7 um die Fähigkeit, Variablen zu verwenden.
 *
 * Der Ausdruck „=c a b“ soll dabei folgendes durchführen: Der Wert des
 * Ausdrucks a wird berechnet und der Variablen c zugewiesen. Danach wird der
 * Wert des Ausdrucks b berechnet, das Ergebnis ist der Wert des
 * Gesamtausdrucks. Dabei muss c ein Variablenname sein. (Als Variablennamen
 * sind die Kleinbuchstaben a bis z zugelassen, d. h., es gibt 26 Variablen.)
 *
 * Weiterhin sind jetzt neben Zahlenkonstanten auch Variablennamen in Ausdrücken
 * zulässig.
 *
 * So soll etwa der Ausdruck „=a + 3 5 * a a“ das Ergebnis 64 liefern.
 *
 * Analog soll der Ausdruck „=a 7 =b + a 2 + a b“ das Ergebnis 16 liefern.
 */

// 20 Punkte

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double vars[26]= { 0.0 };

double calculate(double v) {
	int c = getchar();
	if (isdigit(c))
		return calculate(v * 10 + (c - '0'));
	else if (v == 0 && isspace(c))
		return calculate(0);
	else if (c == '+')
		return calculate(0) + calculate(0);
	else if (c == '-')
		return calculate(0) - calculate(0);
	else if (c == '*')
		return calculate(0) * calculate(0);
	else if (c == ':' || c == '/')
		return calculate(0) / calculate(0);
	else if (islower(c))
		return vars[c - 'a'];
	else if (c == '=') {
		c = getchar();
		vars[c - 'a'] = calculate(0);
		return calculate(0);
	}
	ungetc(c, stdin);
	return v;
}

int main() {
	printf("%.2f\n", calculate(0));
	return 0;
}
