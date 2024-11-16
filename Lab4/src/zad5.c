#include <stdio.h>
#include <stdlib.h>

int silnia(int n) {
	if (n < 0) {
		fprintf(stderr, "N musi być liczbą naturalną!\n");
		exit(-1);
	}

	int f = 1;
	for (int i = n; i > 0; i--) f *= i;
	
	return f;
}

int main(void) {
	int n;
	printf("Podaj n: ");
	scanf("%d", &n);

	int f = silnia(n);
	printf("\n%d! = %d\n", n, f);

	return 0;
}
