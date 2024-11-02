#include <stdio.h>

int main(void) {
	int a, b, c, d;
	
	printf("Podaj a, b, c i d: ");
	if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) {
		fprintf(stderr, "a, b, c i d muszą być liczbami całkowitymi!\n");
		return -1;
	}

	int max;
	int poz;

	if (a >= b) {
		max = a;
		poz = 1;
	} else {
		max = b;
		poz = 2;
	}

	if (c > max) {
		max = c;
		poz = 3;
	}
	if (d > max) {
		max = d;
		poz = 4;
	}

	printf("Max: %d\n", max);
	printf("Pozycja: %d\n", poz);
	
	return 0;
}
