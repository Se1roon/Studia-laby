#include <stdio.h>
#include <math.h>

int main(void) {
	double a, b, c;
	
	printf("Wprowadź długości boków trójkąta a, b, c: ");
	if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
		fprintf(stderr, "Nie udało się poprawnie wczytać długości boków!\n");
		return -1;
	}

	if (a <= 0 || b <= 0 || c <= 0) {
		fprintf(stderr, "Podałeś nieprawidłowe długości boków!\n");
		return -2;
	}

	if (a > b + c || b > a + c || c > a + b) {
		fprintf(stderr, "Taki trójkąt nie istnieje!\n");
		return -3;
	}

	double p = (a + b +c)/2;
	double pole = sqrt(p * (p - a) * (p - b) * (p - c));
	double promien = pole / p;

	printf("Pole: %lf\n", pole);
	printf("Promień koła wpisanego: %lf\n", promien);

	return 0;
}
