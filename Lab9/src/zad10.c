#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct CO {
	double re;
	double im;
} COMPLEX;

// Funkcja zwraca ilość rozwiązań
int calculate_sqrt(double a, double b, double c, COMPLEX *r1, COMPLEX *r2) {
	double delta = b*b - 4*a*c;

	if (delta < 0) {
		r1->re = -b/2*a;
		r1->im = sqrt(fabs((b/2*a)*(b/2*a) - c/a));
		r2->re = r1->re;
		r2->im = -r1->im;
	} else if (delta > 0) {
		r1->re = (-b - sqrt(delta))/2*a;
		r2->re = (-b + sqrt(delta))/2*a;
		r1->im = r2->im = 0;
	} else {
		r1->re = (-b)/2*a;
		r1->im = 0;
		return 1;
	}

	return 2;
}

void add_complex(COMPLEX *n1, COMPLEX *n2, COMPLEX *r) {
	r->re = n1->re + n2->re;
	r->im = n1->im + n2->im;

	return;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <r|d>\n\tr - rozwiazanie rownania\n\td - dodanie 2 liczb zespolonych\n\n", argv[0]);
		return 0;
	}

	if (argv[1][0] == 'd') {
		COMPLEX n1, n2, r;
		printf("Podaj współczynniki (re1 im1 re2 im2): ");
		scanf("%lf %lf %lf %lf", &n1.re, &n1.im, &n2.re, &n2.im);

		add_complex(&n1, &n2, &r);
		printf("(%lf + %lfi) + (%lf + %lfi) = %lf + %lfi\n", n1.re, n1.im, n2.re, n2.im, r.re, r.im);
	} else if (argv[1][0] == 'r') {
		double a, b, c;
		printf("Podaj współczynniki (a b c): ");
		scanf("%lf %lf %lf", &a, &b, &c);

		COMPLEX n1, n2;
		if (calculate_sqrt(a, b, c, &n1, &n2) > 0)
			printf("Results:\n x1 = %lf + %lfi\n x2 = %lf + %lfi\n", n1.re, n1.im, n2.re, n2.im);
		else printf("Results:\n\tx0 = %lf + %lfi\n", n1.re, n1.im);
	}

	return 0;
}



