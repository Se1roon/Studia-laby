#include <stdio.h>
#include <stdbool.h>
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

	int pos = -1;
	int current_pos = 0;
	char current_char;
	while (scanf("%c", &current_char) != EOF) {
		if (current_char == search_char) {
			pos = current_pos;	
			break;
		}
		current_pos++;
	}

	if (pos < 0) printf("\n[%c] has not been found!\n");
	else printf("\n[%c] has been found on position %d\n", current_char, pos);

	return 0;
}
