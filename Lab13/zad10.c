#include <stdio.h>
#include <stdlib.h>


double calc_sum_pom(double a, double b, double (*func)(double), double sum) {
	if (a == b) return sum + func(b);

	return calc_sum_pom(a + 1, b, func, sum + func(a));
}

double calc_sum_ogon(double a, double b, double (*func)(double)) {
	return calc_sum_pom(a, b, func, 0);
}


double calc_sum(double a, double b, double (*func)(double)) {
	if (a == b) return func(b);

	return func(a) + calc_sum(a + 1, b, func);
}


double f(double arg) {
	printf("wywolano f(%lf)\n", arg);

	return 1;
}


int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("%s <a> <b>\n", argv[0]);
		return 0;
	}

	double a = atof(argv[1]);
	double b = atof(argv[2]);

	if (a > b) {
		printf("a musi byc mniejsze lub rowne b!\n");
		return -1;
	}

	double sum = calc_sum_ogon(a, b, &f);
	
	printf("\nF(%lf, %lf, f) = %lf\n", a, b, sum);

	return 0;
}
