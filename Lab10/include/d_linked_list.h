#ifndef D_LINKED_LIST
#define D_LINKED_LIST

#include "common.h"

typedef struct d_linked_list {
	int num_elements;
	STUDENT_D *head;
	STUDENT_D *tail;
} D_LL;

D_LL *d_ll_init(FILE *f);
STUDENT_D *d_ll_max_s(D_LL *list);
int d_ll_count(D_LL *list);
void d_ll_remove_head(D_LL *list);
void d_ll_remove_tail(D_LL *list);
void d_ll_add_head(D_LL *list, STUDENT_D *stud);
void d_ll_add_tail(D_LL *list, STUDENT_D *stud);
void d_ll_print(D_LL *list);
void d_ll_clean(D_LL *list);

#endif
