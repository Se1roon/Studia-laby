#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_BUFF_MAX_LEN	64

typedef struct vector {
	int dim;
	char *str;
	double *buff;
} VEC;

double calc_dot(VEC *vectors);
void add_vector(VEC *vectors, int index);
void clear_vector(VEC *vector);
char *get_line(FILE *f);

int main(void) {
	VEC *vectors = (VEC *)malloc(sizeof(VEC) * 2);
	add_vector(vectors, 0);
	printf("\n");
	add_vector(vectors, 1);
	printf("\n");

	double dot = calc_dot(vectors);
	printf("Iloczyn = %lf\n", dot);

	clear_vector(&vectors[0]);
	clear_vector(&vectors[1]);
	free(vectors);
	return 0;
}

double calc_dot(VEC *vectors) {
	double sum = 0;
	int i = 0;
	while (i < vectors[0].dim) {
		sum += vectors[0].buff[i] * vectors[1].buff[i];
		i++;
	}

	return sum;
}

void add_vector(VEC *vectors, int index) {
	VEC *vector = &vectors[index];

	printf("Podaj wymiar: ");
	char *dim_l = get_line(stdin);
	vector->dim = atoi(dim_l);
	if (vector->dim == 0) {
		fprintf(stderr, "Wymiar jest nieprawidlowy!\n");
		free(dim_l);
		exit(-1);
	}
	free(dim_l);

	printf("Podaj nazwe: ");
	vector->str = get_line(stdin);
	if (strlen(vector->str) > VECTOR_BUFF_MAX_LEN) {
		fprintf(stderr, "Nazwa wektora nie moze przekraczac %d znakow!\n", VECTOR_BUFF_MAX_LEN);
		free(vector->str);
		exit(-1);
	}

	printf("Podaj wartosci: ");
	char *buff_l = get_line(stdin);

	int chars_read = 0;
	int i = 0;
	char *b = NULL;
	b = strtok(buff_l, " ");
	if (b) {
		vector->buff = (double *)calloc(0, sizeof(double));
		do {
			if (chars_read >= vector->dim) {
				fprintf(stderr, "Podano za duzo wartosci!\n");
				fprintf(stderr, "Wczytane zostana tylko pierwsze %d wartosci!\n", vector->dim);
				break;
			}

			vector->buff = (double *)realloc(vector->buff, (i + 1) * sizeof(double));
			vector->buff[i++] = atof(b);
			chars_read++;
		} while ((b = strtok(NULL, " ")));
	}

	free(buff_l);
	return;
}

void clear_vector(VEC *vector) {
	free(vector->str);
	free(vector->buff);

	return;
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
