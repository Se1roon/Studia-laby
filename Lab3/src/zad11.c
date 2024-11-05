#include <stdio.h>

int calc(double x, double y, double *w);

int main(void) {
	double x, y, z;

	printf("Podaj x i y: ");
	scanf("%lf %lf", &x, &y);

	int num = calc(x, y, &z);
	if (num < 0) {
		fprintf(stderr, "Cos poszlo nie tak\n");
		return -1;
	}

	printf("\nx=%lf\ty=%lf\tz=%lf\n", x, y, z);

	return 0;
}

int calc(double x, double y, double *w) {
	if (x * x + y * y <= 1) {
		*w = x * x + y;
		return 1;
	} else if (x + 5 < y) {
		*w = 2 * x + y * y;
		return 2;
	} else {
		*w = (x * x) / 2 + y;
		return 3;
	}

	return -1;
}
