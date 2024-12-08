#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "llist.h"

LLIST *init_list1(FILE *f) {
	LLIST *l = (LLIST *)malloc(sizeof(LLIST));
	l->count = 0;
	l->head = l->tail = NULL;

	STUDENT *p = NULL;
	char *line = NULL;


	while ((line = get_line(f)) && i < 5) {
		s->imie = strtok(line, ",");
		s->nazwisko = strtok(NULL, ",");
		s->rok = atoi(strtok(NULL, ","));
		s->adres = strtok(NULL, ",");
		s->stypendium = atof(strtok(NULL, ","));
		s->next = NULL;

		if (!p) {
			l->head = l->tail = s;
			p = s;
		} else {
			p->next = s;
			l->tail = s;
		}
		l->count++;
	}

	return l;
}


