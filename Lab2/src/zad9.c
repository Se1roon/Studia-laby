#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void my_exit();
static void my_return();

int main(int argc, char* argv[]) {
	double a = 0.0, b = 0.0, c = 0.0;
	int ret = -1;

	printf("Program obliczenia rzeczywistych pierwiastków równania kwadratowego\n");
	printf("-------------------- a*x^2+b*x+c = 0 ------------------------------\n\n");
	printf("Podaj a,b,c\n");

	ret = scanf("%le %le %le", &a, &b, &c);
	if (ret != 3) {
		printf("Błąd przy wczytaniu\n");
		printf("Wczytane: a = %e  b = %e  c = %e\n", a, b, c);
		my_exit();
	}

	if (a == 0.0) {
		printf("To nie jest równanie kwadratowe: a = 0.\n");
		my_exit();
	}

	double x1, x2;
	double D = -1.0;
	D = b*b - 4.0*a*c;
	if (D < 0.0) {
		double r1, r2, u1, u2;
		r1 = -b/2*a;
		r2 = -b/2*a;
		u1 = sqrt(fabs(pow(b/(2*a), 2) - c/a));
		u2 = -sqrt(fabs(pow(b/(2*a), 2) - c/a));

printf("Rownanie kwadratowe: %lf *X*X + %lf *X + %lf = 0\n\n", a, b, c);
printf("Pierwiastki (zespolone): x1 = (r=%lf, u=%lf) x2 = (r=%lf, u=%lf)\n", r1, u1, r2, u2);
printf("---------------------------------------------------------\n");

		my_return();
	}

	double p1, p2;
	p1 = -b/(2.0*a);
	p2 = sqrt(D)/(2.0*a);
	x1 = p1 + p2;
	x2 = p1 - p2;

	printf("Rownanie kwadratowe: %lf *X*X + %lf *X + %lf = 0\n\n", a, b, c);
printf("Pierwiastki: x1 = %e x2 = %e\n", x1, x2);
printf("---------------------------------------------------------\n");

	my_return();

	return 0;
}

void my_exit() {
	int ch;
	printf("Zakoncz - ctrl+Z Enter\n");
	while((ch = getchar()) != EOF)
		;
	exit(1);
}

void my_return() {
	int ch;
	printf("Zakoncz - ctrl+Z Enter\n");
	while((ch = getchar()) != EOF)
		;
	exit(0);
}
