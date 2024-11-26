#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double fp(double);

int newton(double *x, int n, double eps, double (*f)(), double (*fp)());

int main() {
	double x0 = 0.8;
	double eps = 0.001;
	int n = 100;

	if (!newton(&x0, n, eps, f, fp))
		printf("rozwiazanie = %lf wart.= %lf\n", x0, f(x0));
	else
		printf("Brak zbieznosci\n");
	system("pause");
}

int newton(double *x, int n, double eps, double (*f)(double), double (*fp)(double)) {
	double x1;
	int i = 0;

	do {
		x1 = -(*f)(*x) / (*fp)(*x);
		*x += x1;
		if (fabs(x1) < eps) return 0;
	} while (i++ < n);

	return 1;
}

double f(double x) {
	return sin(x) - .5*x;
}

double fp(double x) {
	return cos(x) - .5;
}
