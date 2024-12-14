#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "linked_list.h"
#include "d_linked_list.h"

int main(void) {
	char *filepath = "dane.txt";
	FILE *fd = fopen(filepath, "r");

	D_LL *list = d_ll_init(fd);
	d_ll_print(list);

	d_ll_remove_tail(list);

	printf("\n\n\n");

	d_ll_print(list);

	d_ll_clean(list);
	fclose(fd);
	return 0;
}

