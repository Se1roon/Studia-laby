#include <stdio.h>
#include <math.h>

double ff(double x);

int main(void) {
	double a, b, dx;
	char *out_file = "out.txt";

	printf("Podaj a b dx: ");
	scanf("%lf %lf %lf", &a, &b, &dx);

	FILE *f = fopen(out_file, "w+");

	for (double x = a; x <= b; x += dx) {
		double y = ff(x);
		fprintf(f, "\t%10.2lf\t\t%15.4lf\n", x, y);
		printf("\t%10.2lf\t\t%15.4lf\n", x, y);
	}

	fclose(f);
	return 0;
}

double ff(double x) {
	return 1/(x*x + sqrt(1 + 2*x + 3*x*x));
}
