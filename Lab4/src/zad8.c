#include <stdio.h>

int main(void) {
	int num_a = 0;
	int num_b = 0;
	int num_c = 0;
	int num_other = 0;

	char c;
	while (1) {
		scanf("%c", &c);
		if (c == 'e') break;
		if (c == 'a') {
			num_a++;
			continue;
		}
		if (c == 'b') {
			num_b++;
			continue;
		}
		if (c == 'c') {
			num_c++;
			continue;
		}
		if (c != '\n') num_other++;
	}

	printf("\nLiczba wystąpień 'a': %d\n", num_a);
	printf("Liczba wystąpień 'b': %d\n", num_b);
	printf("Liczba wystąpień 'c': %d\n", num_c);
	printf("Liczba wystąpień innych znaków: %d\n", num_other);

	return 0;
}
