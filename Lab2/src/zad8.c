#include <stdio.h>
#include <math.h>

int main(void) {
	double x, y, z;
	int k, m;

	printf("Podaj x, y, z, k i m (format: x y z k m): ");
	if (scanf("%lf %lf %lf %d %d", &x, &y, &z, &k, &m) != 5) {
		fprintf(stderr, "Nie udało się poprawnie wczytać danych!\n");
		return -1;
	}

	printf("x=%lf\ty=%lf\tz=%lf\tk=%d\tm=%d\n", x, y, z, k, m);

	long double w1 = pow(x / (y * z), 1.0/3) * log(pow(x, 2) + pow(y, 2));
	long double w2 = sin(k * (x/2)) * cos(m * y) + y * exp(2*x - 1);
	long double w3 = fabs(x / (2*pow(y, 2) + 1)) + sqrt(y / (pow(z, 2) + 3)) + 5 * pow(y + z, 3);
	long double w4 = (x/(y*z)) * pow(z + 1, 1.0/3) + pow(pow(x, 2) + pow(z, 2) + 1, 1.0/k) - fabs(y);
	long double w5 = 1/sqrt(pow(x, 2) + pow(y, 2) + pow(k, 2)) + sin(k*y) / x;

	printf("w1 = %Lf\n", w1);
	printf("w2 = %Lf\n", w2);
	printf("w3 = %Lf\n", w3);
	printf("w4 = %Lf\n", w4);
	printf("w5 = %Lf\n", w5);

	return 0;
}
