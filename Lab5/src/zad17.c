#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// String1 dołączony od pozycja na koniec string2
	if (argc != 4) {
		printf("Usage: %s <string1> <string2> <pozycja>\n", argv[0]);
		return 0;
	}

	char *string1 = argv[1];
	char *string2 = argv[2];
	int string1_len = strlen(string1);
	int string2_len = strlen(string2);

	int position = atoi(argv[3]);
	if (position > string1_len || position < 0) {
		fprintf(stderr, "Invalid position!\n");
		return -1;
	}

	int remaining_chars = string1_len - position;

	char *output = (char*)malloc((string2_len + remaining_chars + 1) * sizeof(char));

	memcpy(output, string2, string2_len);
	memcpy(&output[string2_len], &string1[position], remaining_chars + 1);

	printf("%s\n", output);

	free(output);
	return 0;
}
