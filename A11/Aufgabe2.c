/* Aufgabe 2
 *
 * Wie Sie feststellen, werden die Zeilen in Aufgabe 1 in umgekehrter
 * Reihenfolge ausgegeben.
 *
 * Schreiben Sie eine Funktion reverse, die eine Liste umdreht. Diese Funktion
 * darf destruktiv arbeiten.
 *
 * Verwenden Sie die Funktion reverse, um Ihr Programm aus Aufgabe 1 so zu
 * erweitern, dass die Zeilen in der ursprünglichen Reihenfolge ausgegeben
 * werden.
 */

/* komplexitaet der Loesung nicht schoen, da mehrfach bis Ende der Liste
 * (jedesmal ein Element weniger)
 * Besser erstes Element aus alter Liste entnehmen und als letzes der neuen
 * einfuegen, dann immer erste aus alter Liste in neue Liste!
 *
 * aber Loesung des Problems 10/10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
typedef struct node * node_ptr_t;
struct node {
	node_ptr_t next;
	char * text;
	size_t length;
};

node_ptr_t init_node()
{
	node_ptr_t e = (node_ptr_t)calloc(1, sizeof(node_t));
	e->text = (char *)calloc(1, sizeof(char));
	e->length = 0;
	e->next = NULL;

	return e;
}

node_ptr_t reverse(node_ptr_t e)
{
	// gehe zum letzten Element der Liste:
	node_ptr_t h = e;
	while (h->next != NULL) {
		h = h->next;
	}
	// merke dir den neuen Anfang der Liste:
	node_ptr_t new_start = h;

	/* Jetzt drehen wir die Referenzen in der Liste nacheinander um.
	 * h wandert von hinten nach vorne; i ist immer der Vorgänger von h (wir
	 * müssen dabei die Liste immer vom Anfang e durchgehen und h suchen).
	 * Wenn wir den Vorgänger von h gefunden haben, speichern wir die
	 * Referenz um, setzen h auf den ursprünglichen Vorgänger (i) und fangen
	 * von vorne an.
	 * Das machen wir so lange, bis h am ursprünglichen Anfang der Liste
	 * angekommen ist. Dann müssen wir nur noch die Referenz vom
	 * ursprünglichen Anfang auf NULL setzen und fertig.
	 */
	node_ptr_t i;
	while (h != e) {
		i = e;
		while (i->next != h) {
			i = i->next;
		}
		h->next = i;
		h = i;
	}
	e->next = NULL;

	return new_start;
}

void print_node(node_ptr_t e)
{
	for (size_t l = 0; l < e->length; l++) {
		putchar(e->text[l]);
	}
	putchar('\n');
}

void print_list(node_ptr_t e)
{
	while (e != NULL) {
		print_node(e);
		e = e->next;
	}
}

node_ptr_t read_into_list()
{
	node_ptr_t e = init_node();
	node_ptr_t new;

	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			new = init_node();
			new->next = e;
			e = new;
		} else {
			e->text = (char *)realloc(e->text, (e->length+2)*sizeof(char));
			e->text[e->length] = c;
			e->text[e->length+1] = '\0';
			e->length++;
		}
	}

	if (strlen(e->text) == 0) {
		new = e->next;
		free(e);
		e = new;
	}

	return e;
}

void free_list(node_ptr_t e)
{
	node_ptr_t h;
	while (e != NULL) {
		h = e->next;
		free(e);
		e = h;
	}
}

int main(int argc, char *argv[])
{
	node_ptr_t e = read_into_list();

	e = reverse(e);

	print_list(e);

	free_list(e);

	return 0;
}
