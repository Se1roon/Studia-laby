#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

#include "common.h"

typedef struct linked_list {
	int num_elements;
	STUDENT *head;
	STUDENT *tail;
} LL;

LL *ll_init(FILE *f);
STUDENT *ll_max_s(LL *list);
int ll_count(LL *list);
void ll_remove_head(LL *list);
void ll_remove_tail(LL *list);
void ll_add_head(LL *list, STUDENT *stud);
void ll_add_tail(LL *list, STUDENT *stud);
void ll_print(LL *list);
void ll_clean(LL *list);

#endif
