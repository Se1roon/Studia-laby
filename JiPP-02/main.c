#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void zad1() {
	int liczba;
	printf("Podaj liczbe> ");
	scanf("%d", &liczba);

	if (liczba % 2 == 0)
		printf("Parzysta\n");
	else
		printf("Nieparzysta\n");

	return;
}

int zad2() {
	int l1, l2, l3;

	printf("Podaj 3 liczby>");
	scanf("%d %d %d", &l1, &l2, &l3);

	if (l1 > l2) {
		if (l1 > l3) printf(:"%d\n", l1); 
	} else {
		if (l2 > l3) printf("%d\n", l2);
	}

	printf("%d\n", l3);
	return;
}

void zad3() {
	int a[5] = {0};

	int i, j;
	for (i = 0; i < 5; i++) {
		printf("Podaj liczbe> ");
		scanf("%d", &a[i]);
	}
	
	int max = a[0];
	for (int i = 0; i < 5; i++) {
		if (a[i] >= max) max = a[i];
	}

	int min = a[0];
	for (int i = 0; i < 5; i++)
		if (a[i] <= min) min = a[i];


	printf("Max: %d\n", max);
	printf("Min: %d\n", min);

	return;
}

void zad4() {
	int a[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Podaj liczbe> ");
			scanf("%d", &a[i][j]);
		}
	}

	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sum += a[i][j];

	printf("Suma=%d\n", sum);
}

void zad5() {
	int a[10];
	int i;
	for (i = 0; i < 10; i++) {
		printf("Podaj liczbe> ");
		scanf("%d", &a[i]);
	}

	int sum = 0;
	for (i = 0; i < 10; i++)
		sum += a[i];

	printf("Średnia: %f\n", sum / 10.0);
}

void zad6() {
	char cyfra;
	int sum = 0;

	printf("Podaj liczbe> ");

	while (cyfra != '\n') {
		scanf("%c", &cyfra);
		sum += atoi(&cyfra);
	}

	printf("Suma cyfr: %d\n", sum);
}

void zad7() {
	int liczba;

	do {
		printf("Podaj liczbe wieksza od 10> ");
		scanf("%d", &liczba);
	} while (liczba <= 10);

	return;
}

void zad8() {
	int width, height;
	printf("Podaj szerokosc: ");
	scanf("%d", &width);

	printf("Podaj wysokosc: ");
	scanf("%d", &height);

	for (int i = 0; i < width; i++)
		printf("*");
	printf("\n");
	for (int i = 0; i < height - 2; i++) {
		printf("*");
		for (int j = 0; j < width - 2; j++)
			printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < width; i++)
		printf("*");
	printf("\n");

	return;
}

int main() {
	zad8();

	return 0;
}
