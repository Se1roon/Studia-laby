#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Usage: %s <plik> <linia 1> <linia 2>\n", argv[0]);
		return 0;
	}

	char *filepath = argv[1];
	int line_num1 = atoi(argv[2]);
	int line_num2 = atoi(argv[3]);

	if (line_num1 < 0 || line_num2 < 0) {
		fprintf(stderr, "Numery linii nie mogą być ujemne!\n");
		return -1;
	}

	FILE *file = fopen(filepath, "r");
	if (!file) {
		fprintf(stderr, "Nie mogę otworzyć pliku!\n");
		return -2;
	}

	int lines_num = 0;
	char **lines = (char **)calloc(lines_num, sizeof(char *));
	if (!lines) {
		fprintf(stderr, "Problem alokacji pamięci!\n");
		return -3;
	}

	char *line = NULL;
	while ((line = get_line(file))) {
		lines = (char **)realloc(lines, (lines_num + 1) * sizeof(char *));
		lines[lines_num++] = line;
	}

	if (line_num1 >= lines_num || line_num2 >= lines_num) {
		fprintf(stderr, "Ten plik nie ma tylu linii (linie są liczone od 0)!\n");
		return -4;
	}

	char *temp = lines[line_num1];
	lines[line_num1] = lines[line_num2];
	lines[line_num2] = temp;

	for (int i = 0; i < lines_num; i++)
		printf("%s\n", lines[i]);

	for (int i = 0; i < lines_num; i++)
		free(lines[i]);
	free(lines);
	fclose(file);
	return 0;
}

