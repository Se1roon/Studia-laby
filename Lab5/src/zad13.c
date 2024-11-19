#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
	char search_char;

	char c;
	while ((c = getopt(argc, argv, "s:")) != -1) {
		switch (c) {
			case 's':
				search_char = optarg[0];
				break;
			case '?':
				fprintf(stderr, "Unknown option -%c\n", c);
				return -1;
		}
	}

	int positions_size = 0;
	int *positions = (int*)calloc(positions_size, sizeof(int));

	int current_pos = 0;
	char current_char;
	while (scanf("%c", &current_char) != EOF) {
		if (current_char == search_char) {
			positions = (int*)realloc(positions, ++positions_size * sizeof(int));
			positions[positions_size - 1] = current_pos;
		}

		current_pos++;
	}

	if (!positions_size) printf("\n\n[%c] has not been found\n", search_char);
	else {
		printf("\n\n[%c] has been found on positions (including newline characters): ", search_char);
		for (int i = 0; i < positions_size; i++) {
			if (i + 1 == positions_size) printf("%d\n", positions[i]);
			else printf("%d, ", positions[i]);
		}
	}

	free(positions);
	return 0;
}
