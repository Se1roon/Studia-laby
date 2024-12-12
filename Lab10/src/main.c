#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "linked_list.h"

int main(void) {
	char *filepath = "dane.txt";
	FILE *fd = fopen(filepath, "r");

	LL *list = ll_init(fd);
	printf("BEFORE DEL\n");
	ll_print(list);

	ll_remove_tail(list);

	printf("AFTER DEL\n");
	ll_print(list);

	ll_clean(list);
	fclose(fd);
	return 0;
}

