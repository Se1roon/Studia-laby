#include <stdio.h>

void hanoi(int N, char A, char B, char C);

int main(void) {
	int n;

	printf("Podaj n: ");
	scanf("%d", &n);

	printf("\n");

	hanoi(n, 0, 0, 0);

	return 0;
}

void hanoi(int N, char A, char B, char C) {
	if (N == 1) {
		printf("Przenoszę ostatni krążek z kołka A na kołek B\n");
		return;
	}

	if (N > 1) {
		printf("Przenoszę krążek z kołka A na pomocniczy kołek C\n");
		hanoi(N - 1, A, B, C);
		printf("Przenoszę krążek z kołka C na kołek B\n");
	}

	return;
}
