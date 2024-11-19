#include <stdio.h>
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

	int text_size = 0;
	char *text = (char*)calloc(text_size, sizeof(char));

	char current_c;
	while (scanf("%c", &current_c) != EOF) {
		if (current_c != search_char) {
			text = (char*)realloc(text, ++text_size * sizeof(char));
			text[text_size - 1] = current_c;
		}
	}

	printf("\n\nAfter removing [%c]\n", search_char);
	printf("%s\n", text);
	
	free(text);
	return 0;
}
