#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Zła liczba argumentów\n");
		printf("Usage: %s <char do usunięcia> <char do zamiany>\n", argv[0]);
		return -1;
	}

	char del_char = argv[1][0];
	char sub_char = argv[2][0];

	int output_size = 0;
	char *output = (char*)calloc(output_size, sizeof(char));
	char current_c;
	while (scanf("%c", &current_c) != EOF) {
		output = (char*)realloc(output, (output_size + 1) * sizeof(char));
		if (current_c == del_char) 
			output[output_size++] = sub_char;
		else output[output_size++] = current_c;
	}

	printf("\n\nPo zamianie [%c] na [%c]:\n", del_char, sub_char);
	printf("%s\n", output);

	free(output);
	return 0;
}
