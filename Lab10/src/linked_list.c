#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "utils.h"
#include "linked_list.h"

LL *ll_init(FILE *f) {
	LL *list = (LL *)malloc(sizeof(LL));
	list->num_elements = 0;
	list->head = NULL;
	list->tail = NULL;

	STUDENT *s = NULL;
	while ((s = read_student(f))) {
		s->n = NULL;

		if (list->num_elements == 0) list->head = list->tail = s;
		else {
			list->tail->n = s;
			list->tail = s;
		}

		list->num_elements++;
	}

	return list;
}

STUDENT *ll_max_s(LL *list) {
	if (list->num_elements == 0) return NULL;

	STUDENT *current = list->head;
	STUDENT *max = current;
	while (current) {
		if (current->stypendium > max->stypendium) max = current;
		current = current->n;
	}

	return max;
}

int ll_count(LL *list) {
	return list->num_elements;
}

void ll_remove_head(LL *list) {
	if (list->num_elements == 0) return;
	if (list->num_elements == 1) {
		clean_student(list->head);
		list->head = NULL;
		list->tail = NULL;
	} else {
		STUDENT *save = list->head->n;
		clean_student(list->head);
		list->head = save;
	}

	list->num_elements--;
	return;
}

void ll_remove_tail(LL *list) {
	if (list->num_elements == 0) return;
	if (list->num_elements == 1) {
		clean_student(list->tail);
		list->head = NULL;
		list->tail = NULL;
	} else {
		STUDENT *current = list->head;
		while (current->n != list->tail) current = current->n;

		clean_student(list->tail);
		list->tail = current;
		current->n = NULL;
	}
			
	list->num_elements--;
	return;
}

void ll_add_head(LL *list, STUDENT *stud) {
	stud->n = list->head;	
	list->head = stud;

	if (list->num_elements == 0) list->tail = stud;
	
	list->num_elements++;
	return;
}

void ll_add_tail(LL *list, STUDENT *stud) {
	stud->n = NULL;
	list->tail->n = stud;
	list->tail = stud;

	if (list->num_elements == 0) list->head = stud;

	list->num_elements++;
	return;
}

void ll_print(LL *list) {
	STUDENT *s = list->head;
	while (s) {
		printf("Imie: %s\n", s->imie);
		printf("Nazwisko: %s\n", s->nazwisko);
		printf("Rok: %d\n", s->rok);
		printf("Adres: %s\n", s->adres);
		printf("Stypendium: %lf\n\n", s->stypendium);

		s = s->n;
	}

	return;
}

void ll_clean(LL *list) {
	if (list->num_elements == 0) {
		free(list);
		return;
	}

	STUDENT *s = list->head;
	STUDENT *save = NULL;
	while (s) {
		save = s->n;
		clean_student(s);
		s = save;
	}

	free(list);
	return;
}

