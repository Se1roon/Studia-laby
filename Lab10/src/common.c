#include <stdio.h>
#include <stdlib.h>

#include "common.h"

char *get_line(FILE *f) {
	int line_len = 1;
	char *line = (char *)calloc(line_len, sizeof(char));
	if (!line) return NULL;

	int c;
	while ((c = fgetc(f)) != '\n') {
		if (c == EOF) {
			free(line);
			return NULL;
		}

		line = (char *)realloc(line, (line_len + 1) * sizeof(char));
		line[line_len++ - 1] = c;
	}
	line[line_len - 1] = '\0';

	return line;
}


