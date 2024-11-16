#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
	char *filepath = NULL;
	char option;
	while ((option = getopt(argc, argv, "f:")) != -1) {
		switch (option) {
			case 'f':
				filepath = optarg;
				break;
			case '?':
				printf("Usage: %s -f <plik>\n", argv[0]);
		}
	}

	if (!filepath) {
		printf("Usage: %s -f <plik>\n", argv[0]);
		return -1;
	}

	FILE *file = fopen(filepath, "r");
	if (file == NULL) {
		fprintf(stderr, "Nie udalo sie otworzyc pliku!\n");
		return -2;
	}

	char c;
	while (fscanf(file, "%c", &c) != EOF) 
		printf("%c", c);

	fclose(file);
	return 0;
}

