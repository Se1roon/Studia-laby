//==============================PLIK_1===================================
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL 200

extern void error(int, char *);
extern double *DajWekt(int n);
extern void CzytWekt(FILE *fd, double *we, int n);
extern void PiszWekt(FILE *fw, double *we, int n);
extern void DodWekt(double *w1, double *w2, double *w3, int n);
extern double IloczynSkal(double *w1, double *w2, int n);
extern double MaxElem(double *w, int n);

void argumenty(int, char **);


int main(int argc, char *argv[])
{
	double s, mx, my;
	FILE *fw, *fd;
	int n, k;

	double *x = DajWekt(LL);
	double *y = DajWekt(LL);
	double *z = DajWekt(LL);

	argumenty(argc, argv);

	if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
	if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");

	fscanf(fd, "%d", &n);
	CzytWekt(fd, x, n);
	CzytWekt(fd, y, n);

	mx = MaxElem(x, n);
	my = MaxElem(y, n);
	s = IloczynSkal(x, y, n);

	PiszWekt(fw, z, n);

	fprintf(fw, "\nilocz.skal=%lf mx=%lf my=%lf\n", s, mx, my);
}

void argumenty(int argc, char *argv[]) {
	int len;
	char *usage;
	if (argc != 3) {
		len = strlen(argv[0]) + 19;
		if (!(usage = (char*)malloc((unsigned)len * sizeof(char))))
			error(3, "tablica usage");

		strcpy(usage, argv[0]);
		strcat(usage, " file_in file_out");
		error(4, usage);
	}
}

