#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "d_linked_list.h"

void sort(D_LL *list, bool (*cmp_fun)(STUDENT_D *, STUDENT_D *));

bool cmp_fun(STUDENT_D *s1, STUDENT_D *s2) {
	return strncmp(s1->imie, s2->imie, strlen(s1->imie)) > 0;
}

int main(void) {
	char *filepath = "dane.txt";
	FILE *file = fopen(filepath, "r");

	D_LL *list = d_ll_init(file);

	sort(list, cmp_fun);

	d_ll_print(list);
	d_ll_clean(list);

	fclose(file);
	return 0;
}

void sort(D_LL *list, bool (*cmp_fun)(STUDENT_D *, STUDENT_D *)) {
	for (int i = 0; i < list->num_elements; i++) {
		STUDENT_D *current = list->head;
		STUDENT_D *next = NULL;
		while (current && (next = current->n)) {
			if ((*cmp_fun)(current, next)) {
				if (current == list->head) {
					next->p = NULL;
					list->head = next;

					current->n = next->n;
					current->p = next;
					next->n->p = current;
					next->n = current;
				} else if (next == list->tail) {
					current->n = NULL;
					list->tail = current;

					next->n = current;
					next->p = current->p;
					current->p->n = next;
					current->p = next;
				} else {
					current->n = next->n;
					next->n->p = current;
					next->p = current->p;
					next->n = current;
					current->p->n = next;
					current->p = next;
				}
			} else current = current->n;
		}
	}

	return;
}


