#include <stdio.h>
#include <stdlib.h>

double fib(int n) {
	return (n <= 1) ? 1 : fib(n - 2) + fib(n - 1);
}

int main(int argc, char *argv[]) {
	if (argc != 2) return -1;

	printf("%lf\n", fib(atoi(argv[1])));

	return 0;	
}
