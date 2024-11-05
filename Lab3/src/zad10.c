#include <stdio.h>

void zamien(int *x, int *y);

int main(void) {
	int x, y;

	printf("Podaj x i y: ");
	scanf("%d %d", &x, &y);

	printf("\nx=%d\ty=%d", x, y);
	zamien(&x, &y);
	printf("\nx=%d\ty=%d\n", x, y);

	return 0;
}

void zamien(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;

	return;
}
