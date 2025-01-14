#include <stdio.h>
#include <stdlib.h>

double fib_pom(int n, double w) {
	return (n <= 1)	? w + 1 : fib_pom(n - 2, w) + fib_pom(n - 1, w);
}

double fib(int n) {
	return fib_pom(n, 0);
}

int main(int argc, char *argv[]) {
	if (argc != 2) return -1;

	printf("%lf\n", fib(atoi(argv[1])));

	return 0;	
}
