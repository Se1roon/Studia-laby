#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

int contains(char *buff, char *pattern);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s <plik> <szukana fraza>\n", argv[0]);
		return 0;
	}

	char *filepath = argv[1];
	char *str = argv[2];

	FILE *file = fopen(filepath, "r");
	if (!file) {
		fprintf(stderr, "Nie udało się otworzyć pliku!\n");
		return -1;
	}

	int lines_num = 0;
	char **lines = (char **)calloc(lines_num, sizeof(char *));

	char *line = NULL;
	while ((line = get_line(file))) {
		if (contains(line, str) > 0) {
			lines = (char **)realloc(lines, ++lines_num * sizeof(char *));
			lines[lines_num - 1] = line;
		} else free(line);
	}

	for (int i = 0; i < lines_num; i++)
		printf("%s\n", lines[i]);

	for (int i = 0; i < lines_num; i++)
		free(lines[i]);
	free(lines);
	fclose(file);
	return 0;
}

int contains(char *buff, char *pattern) {
	int buff_len = strlen(buff);
	int pattern_len = strlen(pattern);
	
	if (pattern_len > buff_len) return -1;

	for (int i = 0; i < pattern_len; i++)
		if (buff[i] != pattern[i]) return -1;

	return 1;
}

