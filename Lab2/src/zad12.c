#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES
#define __USE_MISC

// Z jakiegoś powodu nie mogłem użyć M_PI więc skopiowałem z pliku math.h
# define M_PI		3.14159265358979323846	/* pi */

double pole_kwadratu(double a);
double obw_kwadratu(double a);
double pole_prostokata(double a, double b);
double obw_prostokata(double a, double b);
double pole_trojkata(double a, double b, double c);
double obw_trojkata(double a, double b, double c);
double pole_kola(double r);
double obw_kola(double r);

int main(void) {
	char figura;
	printf("==================\n");
	printf("|  k - kwadrat   |\n");
	printf("|  p - prostokąt |\n");
	printf("|  t - trójkąt   |\n");
	printf("|  o - koło      |\n");
	printf("==================\n\n");

	printf("> ");
	if (scanf("%c", &figura) != 1) {
		fprintf(stderr, "Nie udało się wczytać twojego wyboru!\n");
		return -1;
	}

	double a, b, c, r, pole, obw;
	switch (figura) {
		case 'k':
			printf("Podaj a: ");
			if (scanf("%lf", &a) != 1) {
				fprintf(stderr, "Bok kwadratu musi być liczbą dodatnią!\n");
				exit(-1);
			}

			pole = pole_kwadratu(a);
			obw = obw_kwadratu(a);

			printf("\nPole: %lf\nObwód: %lf\n", pole, obw);
			break;
		case 'p':
			printf("Podaj a i b: ");
			if (scanf("%lf %lf", &a, &b) != 2) {
				fprintf(stderr, "Boki prostokąta muszą być liczbami dodatnimi!\n");
				exit(-1);
			}

			pole = pole_prostokata(a, b);
			obw = pole_prostokata(a, b);

			printf("\nPole: %lf\nObwód: %lf\n", pole, obw);
			break;
		case 't':
			printf("Podaj a, b i c: ");
			if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
				fprintf(stderr, "Boki trójkąta muszą być liczbami dodatnimi!\n");
				exit(-1);
			}
			
			pole = pole_trojkata(a, b, c);
			obw = obw_trojkata(a, b, c);

			printf("\nPole: %lf\nObwód: %lf\n", pole, obw);
			break;
		case 'o':
			printf("Podaj r: ");
			if (scanf("%lf", &r) != 1) {
				fprintf(stderr, "Promień koła musi być liczbą dodatnią!\n");
				exit(-1);
			}

			pole = pole_kola(r);
			obw = obw_kola(r);

			printf("\nPole: %lf\nObwód: %lf\n", pole, obw);
			break;
		default:
			fprintf(stderr, "Nie wiem co to za figura!\n");
	}

	return 0;
}

double pole_kwadratu(double a) {
	if (a <= 0) {
		fprintf(stderr, "Bok kwadratu musi być dodatni!\n");
		exit(-1);
	}

	return a*a;
}

double obw_kwadratu(double a) {
	if (a <= 0) {
		fprintf(stderr, "Bok kwadratu musi być dodatni!\n");
		exit(-1);
	}

	return 4 * a;
}

double pole_prostokata(double a, double b) {
	if (a <= 0 || b <= 0) {
		fprintf(stderr, "Boki prostokąta muszą być dodatnie!\n");
		exit(-1);
	}

	return a*b;
}

double obw_prostokata(double a, double b) {
	if (a <= 0 || b <= 0) {
		fprintf(stderr, "Boki prostokąta muszą być dodatnie!\n");
		exit(-1);
	}

	return 2*a + 2*b;
}

double pole_trojkata(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		fprintf(stderr, "Boki trójkąta muszą być dodatnie!\n");
		exit(-1);
	}

	if (a > b + c || b > a + c || c > a + b) {
		fprintf(stderr, "Taki trójkąt nie istnieje!\n");
		exit(-1);
	}

	double p = (a + b + c)/2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double obw_trojkata(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		fprintf(stderr, "Boki trójkąta muszą być dodatnie!\n");
		exit(-1);
	}

	if (a > b + c || b > a + c || c > a + b) {
		fprintf(stderr, "Taki trójkąt nie istnieje!\n");
		exit(-1);
	}
	
	return a + b + c;
}

double pole_kola(double r) {
	if (r <= 0) {
		fprintf(stderr, "Promień koła musi być dodatni!\n");
		exit(-1);
	}

	return M_PI * r * r;
}

double obw_kola(double r) {
	if (r <= 0) {
		fprintf(stderr, "Promień koła musi być dodatni!\n");
		exit(-1);
	}

	return 2 * M_PI * r;
}

