/* Aufgabe 4
 *
 * Entwickeln Sie ein Programm zur Bestimmung der Buchstabenhäufigkeiten eines
 * Textes. Bestimmen Sie selbst die Häufigkeitsverteilung für Buchstaben der
 * englischen Sprache. Verwenden Sie hierzu den Text von Herman Melvilles Moby
 * Dick. Geben Sie an, woher sie den Text haben!
 */

// 3 Punkte
// Bekomme nicht annähernd die relativen Werte angezeigt, die ihr angegeben habt
// und die die anderen Gruppen ungefähr haben.

/*
https://www.gutenberg.org/ebooks/2701
http://www.gutenberg.org/cache/epub/2701/pg2701.txt
a:  8.16
b:  1.77
c:  2.39
d:  4.01
e: 12.29
f:  2.19
g:  2.19
h:  6.56
i:  6.88
j:  0.12
k:  0.85
l:  4.47
m:  2.44
n:  6.89
o:  7.31
p:  1.83
q:  0.16
r:  5.51
s:  6.72
t:  9.25
u:  2.81
v:  0.90
w:  2.33
x:  0.11
y:  1.78
z:  0.07
*/

#include <stdio.h>
#include <ctype.h>

int main() {
	int i, c, count, letters[26] = {0};

	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			count++;
			letters[tolower(c) - 'a']++;
		}
	}
	for (i = 0; i < 26; i++)
		printf("%c: %5.2f\n", i + 'a', letters[i] / (float)count * 100);
	return 0;
}
