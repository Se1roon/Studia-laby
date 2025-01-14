#include <stdio.h>
#include <stdlib.h>

int npow_pom(int num, unsigned int n, int res) {
	return (n == 0) ? res : npow_pom(num, n - 1, res) * num;
}

int npow_ogon(int num, unsigned int n) {
	return npow_pom(num, n, 1);
}

int npow(int num, unsigned int n) {
	return (n == 0) ? 1 : npow(num, n - 1) * num;
}

int main(int argc, char *argv[]) {
	if (argc != 3) return -1;

	int num = atoi(argv[1]);
	unsigned int n = atoi(argv[2]);

	printf("%d^%d = %d\n", num, n, npow_ogon(num, n));

	return 0;
}
