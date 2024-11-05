#include <stdio.h>

int sum(int n);

int main(void) {
	int n;
	
	printf("Podaj n: ");
	scanf("%d", &n);

	int suma = sum(n);
	printf("Suma=%d\n", suma);

	return 0;
}

int sum(int n) {
	if (n <= 0) return n;

	return n + sum(n - 1);
}
