#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void switch_elements(char **lines, int lines_num);

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

	int lines_num = 0;
	char **lines = (char **)calloc(lines_num, sizeof(char *));

	char *line = NULL;
	while ((line = get_line(file))) {
		lines = (char **)realloc(lines, ++lines_num * sizeof(char *));
		lines[lines_num - 1] = line;
	}
	fclose(file);

	if (line_to_put >= lines_num || line_position + 1 >= lines_num) {
		fprintf(stderr, "Plik nie ma tyli linii (linie są liczone od 0)!\n");
		return -3;
	}

	for (int i = 0; i < lines_num; i++)
		printf("%s\n", lines[i]);
	

	for (int i = 0; i < lines_num; i++) free(lines[i]);
	free(line);
	return 0;
}

void switch_elements(char **lines, int lines_num) {
	char *temp1;
	char *temp2;
	for (int i = 1; i + 1 < lines_num; i++) {
		if (i == 1) {
			temp1 = lines[i + 1];
			lines[i + 1] = lines[i];
		} else {
			temp2 = lines[i + 1];
			lines[i + 1] = temp1;
			temp1 = temp2;
		}
	}

	temp2 = lines[0];
	lines[0] = temp1;
	lines[1] = temp2;

	return;
}

