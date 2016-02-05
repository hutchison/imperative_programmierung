/* Aufgabe 3, 4, 5
 *
 * 3. Schreiben Sie eine Funktion merge, die zwei sortierte Listen zu einer
 *    sortierten Liste zusammenmischt (auch merge darf destruktiv arbeiten).
 * 4. Schreiben Sie eine Funktion split, die eine Liste destruktiv in zwei
 *    Listen gleicher Länge aufteilt.
 *    Was machen Sie bei Listen mit ungerader Länge?
 * 5. Schreiben Sie ein Programm, das eine Textdatei einliest und die Zeilen
 *    sortiert ausgibt, wobei Sie folgende Strategie verwenden können:
 *      * Einlesen in dynamische Liste
 *      * Sortieren der Liste
 *      * Ausgeben der sortierten Liste
 *    Für das Sortieren einer Liste können Sie folgende rekursive Strategie
 *    verwenden:
 *      * Eine Liste mit weniger als zwei Elementen ist bereits sortiert
 *      * Eine Liste mit zwei oder mehr Elementen wird folgendermaßen sortiert:
 *        - Zerlegen Sie die Liste in zwei gleichlange Teillisten.
 *        - Sortieren Sie die Teillisten
 *        - Mischen Sie die sortierten Teillisten in eine sortierte Gesamtliste.
 */

/* Mergesort ok
 * Aufgabe 3 10/10
 * Aufgabe 4 10/10
 * Aufgabe 5 10/10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node node_t;
typedef struct node * node_ptr_t;
struct node {
	char * text;
	size_t length;
	node_ptr_t next;
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

int nodecmp(node_ptr_t a, node_ptr_t b)
{
	if (a->length == 0) {
		return -1;
	} else if (b->length == 0) {
		return 1;
	} else {
		return strcmp(a->text, b->text);
	}
}

/* Gibt das letzte Element der Liste zurück. */
node_ptr_t last(node_ptr_t a)
{
	node_ptr_t r = a;
	while (r->next != NULL) {
		r = r->next;
	}
	return r;
}

/* Hängt b an a ran. */
void append(node_ptr_t a, node_ptr_t b)
{
	node_ptr_t l = last(a);
	l->next = b;
}

node_ptr_t merge(node_ptr_t a, node_ptr_t b)
{
	if (a == NULL) return b;
	if (b == NULL) return a;

	if (nodecmp(a, b) <= 0) {
		a->next = merge(a->next, b);
		return a;
	} else {
		b->next = merge(b->next, a);
		return b;
	}
}

size_t length(node_ptr_t a)
{
	size_t n = 0;
	node_ptr_t h = a;

	while (h != NULL) {
		h = h->next;
		n++;
	}

	return n;
}

/* Gibt das n. Element der Liste zurück.
 * Dabei fangen wir wie immer bei 0 an zu zählen.
 */
node_ptr_t getn(node_ptr_t a, size_t n)
{
	if (n == 0) {
		return a;
	} else {
		return getn(a->next, n-1);
	}
}

/* Teilt die Liste in zwei Listen auf.
 * Dabei ist h das Element, bei dem die Trennung erfolgen soll, und i ist der
 * Anfang der neuen Liste. Wir löschen die Referenz von h->next und geben i
 * zurück.
 *
 * Ist die Liste von gerade Länge, dann sind die neuen Listen genau halb so lang
 * und gleich groß.
 * Wenn die Liste l von ungerader Länge ist, dann wird l auf die Länge (n-1)/2
 * verkürzt und die zurückgegebene Liste hat die Länge (n+1)/2.
 */
node_ptr_t split(node_ptr_t l)
{
	size_t n = length(l)/2;

	node_ptr_t h = getn(l, n-1);
	node_ptr_t i = h->next;
	h->next = NULL;

	return i;
}

node_ptr_t msort(node_ptr_t l)
{
	if (length(l) < 2) {
		return l;
	} else {
		node_ptr_t l1 = l;
		node_ptr_t l2 = split(l);

		l1 = msort(l1);
		l2 = msort(l2);

		return merge(l1, l2);
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

	e = msort(reverse(e));

	print_list(e);

	free_list(e);

	return 0;
}
