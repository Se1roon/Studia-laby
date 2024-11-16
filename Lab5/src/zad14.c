#include <stdio.h>
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

	char *text;


	
	printf("%s", text);

	return 0;
}
