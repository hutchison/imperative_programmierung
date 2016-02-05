/* Aufgabe 5
 *
 * Schreiben Sie ein Programm, das Rekursion verwendet, um Ausdrücke in
 * Präfix-Notation auszuwerten, die über die Standardeingabe an das Programm
 * geliefert werden.
 *
 * Beispielsweise hat der Ausdruck * + 2 34 567 den Wert 20412. Ausdrücke können
 * die vier Grundrechenarten und mehrstellige Zahlen enthalten, sowie
 * Leerzeichen und Zeilenvorschub.
 *
 * Hinweis: Nehmen Sie an, Sie haben eine Funktion calculate, die den Wert eines
 * Ausdrucks liefern soll. Wenn calculate feststellt, dass das nächste
 * Eingabezeichen das „*“ ist, dann erhalten Sie in
 * diesem Fall das Resultat durch den C-Ausdruck „calculate() * calculate()“.
 */

// 15 Punkte

#include <stdio.h>
#include <ctype.h>

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
	ungetc(c, stdin);
	return v;
}

int main() {
	printf("%.2f\n", calculate(0));
	return 0;
}
