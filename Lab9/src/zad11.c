#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct student {
	char* imie;
	char* nazwisko;
	int rok;
	char* adres;
	double stypendium;
} STUDENT;

int read_student(FILE *fd, STUDENT **s);
char *get_line(FILE *f);
STUDENT **sort_students(STUDENT **students, int students_count);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <plik>\n", argv[0]);
		return 0;
	}

	char *filepath = argv[1];
	FILE *file_fd = fopen(filepath, "r");
	if (!file_fd) {
		fprintf(stderr, "Nie udało się otworzyć pliku!\n");
		return -1;
	}

	int students_num = 1;
	STUDENT **students = (STUDENT **)calloc(1, sizeof(STUDENT *));
	if (!students) {
		fprintf(stderr, "Błąd alokacji pamięci!\n");
		fclose(file_fd);
		return -2;
	}

	while(1) {
		if (read_student(file_fd, &students[students_num - 1]) < 0) break;
		students = (STUDENT **)realloc(students, (students_num++ + 1) * sizeof(STUDENT *));
	}
	fclose(file_fd);

	double max_stypendium = -1;
	for (int i = 0; i < students_num - 1; i++) 
		if (students[i]->stypendium > max_stypendium) max_stypendium = students[i]->stypendium;

	printf("Najwieksze stypendium: %lf\n", max_stypendium);

	students = sort_students(students, students_num - 1);

	for (int i = 0; i < students_num - 1; i++)
		printf("Student %d: %s %s %d %s %lf\n", i, students[i]->imie, students[i]->nazwisko, students[i]->rok, students[i]->adres, students[i]->stypendium);

	for (int i = 0; i < students_num - 1; i++) {
		free(students[i]->imie);
		free(students[i]->nazwisko);
		free(students[i]->adres);
		free(students[i]);
	}
	free(students);
	return 0;
}

int read_student(FILE *fd, STUDENT **student) {
	char *line = get_line(fd);
	if (!line) return -1;

	STUDENT *s = (STUDENT *)malloc(sizeof(STUDENT));

	char *current_student_field = "imie";
	int field_size = 0;
	char *current_field = (char *)calloc(field_size, sizeof(char));
	for (int i = 0; i < strlen(line); i++) {
		if (line[i] == ';') {
			current_field[field_size] = '\0';

			if (!strncmp(current_student_field, "imie", 4)) {
				s->imie = (char *)calloc(strlen(current_field) + 1, sizeof(char));
				strncpy(s->imie, current_field, strlen(current_field) + 1);
				current_student_field = "nazwisko";
			} else if (!strncmp(current_student_field, "nazwisko", 8)) {
				s->nazwisko = (char *)calloc(strlen(current_field) + 1, sizeof(char));
				strncpy(s->nazwisko, current_field, strlen(current_field) + 1);
				current_student_field = "rok";
			} else if (!strncmp(current_student_field, "rok", 3)) {
				s->rok = atoi(current_field);
				current_student_field = "adres";
			} else if (!strncmp(current_student_field, "adres", 5)) {
				s->adres = (char *)calloc(strlen(current_field) + 1, sizeof(char));
				strncpy(s->adres, current_field, strlen(current_field) + 1);
				current_student_field = "stypendium";
			} else if (!strncmp(current_student_field, "stypendium", 10)) {
				s->stypendium = atof(current_field);
				current_student_field = NULL;
			} else {
					fprintf(stderr, "Unexpected error!\n");
					exit(-10);
			}

			free(current_field);
			field_size = 0;
			current_field = (char *)calloc(field_size, sizeof(char));
		} else {
			current_field = (char *)realloc(current_field, (field_size + 1) * sizeof(char));
			current_field[field_size++] = line[i];
		}
	}

	*student = s;

	free(line);
	free(current_field);
	return 0;
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

STUDENT **sort_students(STUDENT **students, int students_count) {
	for (int i = 0; i + 1 < students_count; i++) {
		STUDENT *current = students[i];

		int highest_index = i + 1;
		STUDENT *highest = students[highest_index];
		for (int j = i + 1; j < students_count; j++) {
			if (students[j]->stypendium > highest->stypendium) {
				highest = students[j];
				highest_index = j;
			}
		}

		if (highest->stypendium > students[i]->stypendium) {
			students[i] = highest;
			students[highest_index] = current;
		}
	}

	return students;
}


