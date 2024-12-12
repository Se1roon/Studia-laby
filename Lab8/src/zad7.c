#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_line(FILE *f);
double **load_matrix(FILE *f, int *matrix_size);
double calc_sum(double **M, int M_size, double, double);

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Usage: %s <ścieżka do pliku z macierzą> <początek przedziąłu> <koniec>\n", argv[0]);
		return 0;
	}
	
	char *filepath = argv[1];
	FILE *f = fopen(filepath, "r");
	if (!f) {
		fprintf(stderr, "Nieudało się otworzyć pliku!\n");
		return -1;
	}
	double ps = atof(argv[2]);
	double pk = atof(argv[3]);

	int matrix_size = -1;
	double **matrix = load_matrix(f, &matrix_size);
	if (!matrix) {
		fprintf(stderr, "Podana macierz nie jest kwadratowa!\n");
		fclose(f);
		return -2;
	}

	printf("Suma = %lf\n", calc_sum(matrix, matrix_size, ps, pk));
	
	for (int i = 0; i < matrix_size; i++) free(matrix[i]);
	free(matrix);

	fclose(f);
	return 0;
}

double calc_sum(double **M, int M_size, double x, double y) {
	double sum = 0;
	for (int row = 1; row < M_size; row++)
		for (int k = 0; k < row; k++)
			if (M[row][k] >= x && M[row][k] <= y) sum += M[row][k];

	return sum;
}

double **load_matrix(FILE *f, int *matrix_size) {
	double **M = (double **)calloc(0, sizeof(double *));

	int rows = 0;
	int cols = 0;

	char *line = NULL;
	while ((line = get_line(f))) {
		M = (double **)realloc(M, (rows + 1) * sizeof(double *));
		M[rows] = (double *)calloc(0, sizeof(double));

		char *w = strtok(line, " ");
		while (w) {
			double n = atof(w);
			M[rows] = (double *)realloc(M[rows], (cols + 1) * sizeof(double));
			M[rows][cols++] = n;
			w = strtok(NULL, " ");
		}

		rows++;
		cols = 0;

		free(line);
		line = NULL;
	}

	*matrix_size = rows;
	return M;
}

char *get_line(FILE *f) {
	int line_len = 0;
	char *line = (char *)calloc(line_len, sizeof(char));
	if (!line) return NULL;

	int c;
	while ((c = fgetc(f)) != '\n') {
		if (c == EOF) {
			free(line);
			return NULL;
		}

		line = (char *)realloc(line, (line_len + 1) * sizeof(char));
		line[line_len++] = c;
	}
	line[line_len] = '\0';

	return line;
}

