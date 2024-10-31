#include <stdio.h>
#include <stdbool.h>

#define CURRENT_YEAR	2024

int main(void) {
	int birthyear = -1;

	printf("Podaj rok swojego urodzenia: ");
	if (scanf("%d", &birthyear) != 1) {
		printf("Podana wartość musi być dodatnią liczbą całkowitą!\n");
		return -1;
	}

	if (birthyear < 0) {
		printf("Podałeś nieprawidłowy rok urodzenia!\n");
		return -2;
	}

	int age = CURRENT_YEAR - birthyear;
	printf("Masz %d lat.\n", age);

	return 0;
}
