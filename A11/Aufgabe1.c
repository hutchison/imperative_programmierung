/* Aufgabe 1
 *
 * Schreiben Sie ein Programm, das eine Textdatei zeilenweise in eine einfach
 * verkettete dynamische Liste einliest und diese Liste wieder ausgibt.
 */

/* Zeichenweise mit realloc das Feld vergroessern ist zwar nicht schoen,
 * aber Loesung ist ok.
 * Besser Zeichenkette in Buffer (char[100]) einlesen und dann einmal Speicher
 * in Liste reservieren und kopieren
 * Aufgabe 1 10/10
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

	print_list(e);

	free_list(e);

	return 0;
}
