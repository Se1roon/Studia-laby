#ifndef LLIST_H
#define LLIST_H

typedef struct llist {
	int count;
	void *head;
	void *tail;
} LLIST;

LLIST *init_list1(FILE *f);

#endif
