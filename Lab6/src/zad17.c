#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Usage: %s <plik> <linia którą wstawić> <pozycja po której wstawić>\n", argv[0]);
		return 0;
	}

	char *filepath = argv[1];
	int line_to_put = atoi(argv[2]);
	int line_position = atoi(argv[3]);

	if (line_to_put < 0 || line_position < 0) {
		fprintf(stderr, "Numery linie nie mogą być ujemne!\n");
		return -1;
	}

	FILE *file = fopen(filepath, "r");
	if (!file) {
		fprintf(stderr, "Nie udało się otworzyć pliku!\n");
		return -2;
	}

	char *current_line = NULL;
	char *saved_line = NULL;
	int i = 0;
	while ((current_line = get_line(file))) {
		if (i == line_to_put) saved_line = current_line;
		if (i == line_position + 1) printf("%s\n", saved_line);
		else printf("%s\n", current_line);
		i++;

		if (current_line != saved_line) free(current_line);
	}
	free(current_line);
	free(saved_line);

	fclose(file);
	return 0;
}

