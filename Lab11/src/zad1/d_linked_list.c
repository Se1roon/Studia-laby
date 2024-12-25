#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "utils.h"
#include "d_linked_list.h"

D_LL *d_ll_init(FILE *f) {
	D_LL *list = (D_LL *)malloc(sizeof(D_LL));
	list->num_elements = 0;
	list->head = NULL;
	list->tail = NULL;

	STUDENT_D *s = NULL;
	while ((s = (STUDENT_D *)read_student(f))) {
		s->n = NULL;
		s->p = NULL;

		if (list->num_elements == 0) list->head = list->tail = s;
		else {
			s->p = list->tail;
			list->tail->n = s;
			list->tail = s;
		}

		list->num_elements++;
	}

	return list;
}

STUDENT_D *d_ll_max_s(D_LL *list) {
	if (list->num_elements == 0) return NULL;

	STUDENT_D *current = list->head;
	STUDENT_D *max = current;
	while (current) {
		if (current->stypendium > max->stypendium) max = current;
		current = current->n;
	}

	return max;
}

int d_ll_count(D_LL *list) {
	return list->num_elements;
}

void d_ll_remove_head(D_LL *list) {
	if (list->num_elements == 0) return;
	if (list->num_elements == 1) {
		clean_student((STUDENT*)(list->head));
		list->head = NULL;
		list->tail = NULL;
	} else {
		STUDENT_D *save = list->head->n;

		clean_student((STUDENT*)(list->head));
		list->head = save;
		list->head->p = NULL;
	}

	list->num_elements--;
	return;
}

void d_ll_remove_tail(D_LL *list) {
	if (list->num_elements == 0) return;
	if (list->num_elements == 1) {
		clean_student((STUDENT *)(list->tail));
		list->head = NULL;
		list->tail = NULL;
	} else {
		STUDENT_D *before = list->tail->p;

		clean_student((STUDENT*)(list->tail));
		list->tail = before;
		list->tail->n = NULL;
	}
			
	list->num_elements--;
	return;
}

void d_ll_add_head(D_LL *list, STUDENT_D *stud) {
	if (list->num_elements == 0) {
		list->head = list->tail = stud;
		stud->n = NULL;
		stud->p = NULL;
		list->num_elements++;
		return;
	}

	stud->n = list->head;
	stud->p = NULL;
	list->head->p = stud;
	list->head = stud;

	list->num_elements++;
	return;
}

void d_ll_add_tail(D_LL *list, STUDENT_D *stud) {
	if (list->num_elements == 0) {
		list->head = list->tail = stud;
		stud->n = NULL;
		stud->p = NULL;
		list->num_elements++;
		return;
	}

	stud->n = NULL;
	stud->p = list->tail;
	list->tail->n = stud;
	list->tail = stud;

	list->num_elements++;
	return;
}

void d_ll_print(D_LL *list) {
	STUDENT_D *s = list->head;
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

void d_ll_clean(D_LL *list) {
	if (list->num_elements == 0) {
		free(list);
		return;
	}

	STUDENT_D *s = list->head;
	STUDENT_D *save = NULL;
	while (s) {
		save = s->n;
		clean_student((STUDENT*)s);
		s = save;
	}

	free(list);
	return;
}
