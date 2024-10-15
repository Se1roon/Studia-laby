#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZAD1_SIZE	255

int get_str_len(char str[]) {
	int i = 0;
	while (1) {
		if (str[i] == '\0' || str[i] == '\n') break;
		i++;
	}

	return i + 1;
}

void zad1() {
	char buf[ZAD1_SIZE];
	fgets(buf, ZAD1_SIZE, stdin);
	printf("> %s\n", buf);

	return;
}

void zad2() {
	char buf1[255];
	char buf2[255];

	fgets(buf1, 255, stdin);
	fgets(buf2, 255, stdin);

	int buf1_len = get_str_len(buf1);
	int buf2_len = get_str_len(buf2);

	if (buf1_len > buf2_len)
		strncpy(buf2, buf1, 255);
	else fprintf(stderr, "Pierwsza linia jest krótsza od drugiej.\n");

	printf("Pierwsza linia: %s", buf1);
	printf("Druga linia: %s", buf2);

	return;
}

void zad3() {
	char buf1[255];
	char buf2[255];
	char buf3[255];

	fgets(buf1, 255, stdin);
	fgets(buf2, 255, stdin);
	fgets(buf3, 255, stdin);

	int buf1_len = get_str_len(buf1) + 1; 
	int buf2_len = get_str_len(buf2) + 1;
	int buf3_len = get_str_len(buf3) + 1;

	if (buf1_len + buf2_len + buf3_len> 255) {
		fprintf(stderr, "za duzo");
		return;
	}

	// Wiem ze moze byc segfault idc
	buf1[buf1_len - 2] = ',';
	buf1[buf1_len - 1] = ' ';
	buf1[buf1_len] = '\0';

	buf2[buf2_len - 2] = ',';
	buf2[buf2_len - 1] = ' ';
	buf2[buf2_len] = '\0';

	buf3[buf3_len] = '\0';

	strncat(buf1, buf2, 255);
	strncat(buf1, buf3, 255);

	printf("\n");

	printf("%s\n", buf1);

	return;
}

void zad4() {
	char buf[255];
	char znak;
	fgets(buf, 255, stdin);
	printf("Znak: ");
	scanf("%c", &znak);
	
	int i = 0;
	int count = 0;
	int *indexes = (int*)malloc(count * sizeof(int));
	char current = buf[i];
	while (current != '\0' || i < 255) {
		if (current == znak) {
			count++;
			realloc(indexes, count * sizeof(int));
			indexes[count - 1] = i;
		}
		i++;
		current = buf[i];
	}

	printf("Ilość wystąpień: %d\n", count);
	printf("Indeksy: ");
	for (int i = 0; i < count; i++)
		printf("%d ", indexes[i]);
	printf("\n");

	free(indexes);
	return;
}

void zad5() {
	char buf[255];
	fgets(buf, 255, stdin);
	char out_buf[255];

	int buf_len = get_str_len(buf) - 2;
	int i = buf_len;
	for (; i >= 0; i--) 
		out_buf[buf_len - i] = buf[i];

	printf("Dane wejściowe: %s", buf);
	printf("Dane wyjściowe: %s\n", out_buf);

	return;
}

int contains(int *arr, int i, int len) {
	for (int j = 0; j < len; j++) 
		if (arr[j] == i) return 1;
	return 0;
}

void zad6() {
	char buf[5][255];
	int sort_indexes[5];

	for (int i = 0; i < 5; i++)
		fgets(buf[i], 255, stdin);

//	["a", "b", "d", "e", "F"]

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			if (i+1 < 5 && strncmp(buf[i], buf[i+1], 255) < 0) {
				char temp[255];
				strncpy(temp, buf[i], 255);
				strncpy(buf[i], buf[i+1], 255);
				strncpy(buf[i+1], temp, 255);
			}
		}
	}
	


	printf("\n");
	
	for (int i = 0; i < 5; i++)
		printf("%s", buf[i]);

	return;
}

int main(void) {
	zad6();

	return 0;
}
