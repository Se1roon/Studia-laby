#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(char *argv[]) {
	printf("Usage: %s <string 1> <string 2>\n", argv[0]);
	return;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		print_usage(argv);
		return 0;
	}

	char *text1 = argv[1];
	char *text2 = argv[2];

	char *output = (char*)malloc(strlen(text1) + strlen(text2) + 1); 
	if (!output) {
		fprintf(stderr, "Unable to allocate memory!\n");
		return -1;
	}

	memcpy(output, text1, strlen(text1));
	memcpy(&output[strlen(text1)], text2, strlen(text2) + 1);

	printf("%s\n", output);

	free(output);
	return 0;
}
