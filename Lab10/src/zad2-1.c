#include <stdio.h>

#include "common.h"
#include "llist.h"

int main() {
	char *filepath = "./dane.txt";
	FILE *f = fopen(filepath, "r");
	
	LLIST *list = init_list1(f);

	STUDENT *current = list->head;
	int i = 1;
	while (current != NULL) {
		printf("STUDENT %d:\n", i++);
		printf("| imie: %s\n", current->imie);
		printf("| nazwisko: %s\n", current->nazwisko);
		printf("| rok: %d\n", current->rok);
		printf("| adres: %s\n", current->adres);
		printf("| stypendium: %lf\n", current->stypendium);
		printf("\n");
	}

	fclose(f);
	return 0;
}
