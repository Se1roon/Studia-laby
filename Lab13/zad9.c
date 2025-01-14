#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime_pom(int n, int div, bool res) {
	if (!res) return res;

	return (div >= n) ? res : ((n % div == 0) ? is_prime_pom(n, div + 1, 0) : is_prime_pom(n, div + 1, 1));
}

bool is_prime_ogon(int n, int div) {
	return is_prime_pom(n, div, 1);
}

bool is_prime(int n, int div) {
	if (div >= n) return true;
	if (n % div == 0) return false;

	return is_prime(n, div + 1);
}

int main(int argc, char *argv[]) {
	if (argc != 2) return 0;

	int n = atoi(argv[1]);

	if (is_prime_ogon(n, 2)) printf("Pierwsza\n");
	else printf("Nie pierwsza\n");

	return 0;
}
