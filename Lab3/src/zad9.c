#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M_PI 3.141592653589793238462643383279502984

void kolo(double r, double *w1, double *w2);

int main(void) {
	double r = 0;
	double pole, obwod;
	printf("Podaj promien: ");
	if (scanf("%lf", &r) != 1) {
		fprintf(stderr, "Promien musi byc liczba!\n");
		return -1;
	}

	kolo(r, &pole, &obwod);
	printf("\nPole: %lf\nObwod: %lf\n", pole, obwod);

	return 0;
}

void kolo(double r, double *w1, double *w2) {
	if (r < 0) {
		fprintf(stderr, "Podany promien jest nieprawidlowy!\n");
		exit(-1);
	}

	*w1 = M_PI * r * r;
	*w2 = 2 * M_PI * r;
	
	return;
}
