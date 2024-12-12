#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "utils.h"

void clean_student(STUDENT *s) {
	free(s->imie);
	free(s->nazwisko);
	free(s->adres);
	free(s);
	return;
}

STUDENT *read_student(FILE *f) {
	STUDENT *student = (STUDENT *)malloc(sizeof(STUDENT));

	if (!(student->imie = get_line(f))) {
		free(student);
		return NULL;
	}

	if (!(student->nazwisko = get_line(f))) {
		free(student);
		return NULL;
	}

	char *year = get_line(f);
	if (!year) {
		free(student);
		return NULL;
	}
	student->rok = atoi(year);
	free(year);

	if (!(student->adres = get_line(f))) {
		free(student);
		return NULL;
	}

	char *stypendium = get_line(f);
	if (!stypendium) {
		free(student);
		return NULL;
	}
	student->stypendium = atof(stypendium);
	free(stypendium);

	return student;
}

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

