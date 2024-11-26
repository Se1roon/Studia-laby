#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double g(double x, double (*f)()) {
	return x * x + f(x);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Podaj x\n");
		return -1;
	}

	double x = (double)atoi(argv[1]);
	double res_sin = g(x, sin);
	double res_cos = g(x, cos);

	printf("Sinus: %lf\n", res_sin);
	printf("Cosinus: %lf\n", res_cos);

	return 0;
}
