# Aufgabe 3

Betrachten Sie die folgende Funktionsdefinition:

```c
double fnord(double v) {
  int c = getchar();
  if(c>=’0’ && c<=’9’) return fnord(v*10+(c-’0’));
  ungetc(c,stdin);
  return v;
}
```
Erläutern Sie, was diese Funktion macht und wie sie es macht.

# Lösung

Die Funktion `fnord` liest eine Zahl von der Standardeingabe ein und gibt sie
als `double` zurück. Dabei wird rekursiv bei jedem Funktionsaufruf eine
„Ziffer“ (als ASCII-Zeichen) eingelesen. Falls das Zeichen zwischen 0
und 9 liegt (also eine Ziffer ist), wird es in den numerischen Wert
umgerechnet (`c-'0'`) und auf die bis dahin eingelesene Zahl addiert. Die
bis dahin eingelesene Zahl wird dabei mit 10 multiplizert, was dem dezimalen
Zahlensystem geschuldet ist (`return fnord(v*10+(c-'0'));`).

Um mit `fnord` eine Zahl von der Standardeingabe einzulesen, muss der
Startwert 0 sein, also muss `fnord(0)` aufgerufen werden.

5 Punkte
