#include <stdio.h>
#include <stdlib.h>

extern void error(int, char *);

double *DajWekt(int n) {
	double *wekt = (double *)calloc(n, sizeof(double));
	if (!wekt)
		error(3, "tablica wektor");

	return wekt;
}

void CzytWekt(FILE *fd, double *we, int n) {
	for (int k = 0; k < n; k++)
		fscanf(fd, "%lf", we[k]);
	return;
}

void PiszWekt(FILE *fw, double *we, int n) {
	for (int k = 0; k < n; k++) {
		fprintf(fw, "%lf ", we[k]);
		if (!((k + 1) % 5)) fprintf(fw, "\n");
	}
	return;
}
