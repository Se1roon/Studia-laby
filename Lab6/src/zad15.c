#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN	255

int main(void) {
	FILE *fd = fopen("dane.txt", "r+");
	if (!fd) {
		fprintf(stderr, "Nie znaleziono pliku!\n");
		return -1;
	}

	int num1, num2;
	printf("Podaj linie, które zamienić miejscami: ");
	if (scanf("%d %d", &num1, &num2) != 2) {
		fprintf(stderr, "Liczby podać prosze!\n");
		return -2;
	}

	char *lines[MAX_LINE_LEN];

	int num_of_lines = 0;
	int i = 0;
	while((lines[i] = (char *)calloc(MAX_LINE_LEN, sizeof(char))) && (fgets(lines[i++], MAX_LINE_LEN, fd) != NULL))
		num_of_lines++;

	char *temp = lines[num1 - 1];
	lines[num1 - 1] = lines[num2 - 1];
	lines[num2 - 1] = temp;

	fseek(fd, 0, SEEK_SET);
	for (i = 0; i < num_of_lines; i++)
		fprintf(fd, "%s", lines[i]);
	
	for (i = 0; i < num_of_lines)

	return 0;
}
