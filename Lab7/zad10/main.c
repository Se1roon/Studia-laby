#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void fill_array(int *, int);
int find_min(int *arr, int arr_len, int *pos);
int find_max(int *arr, int arr_len, int *pos);

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "Niepoprawna wielkość tablicy!\n");
		return -1;
	}

	int *t1 = (int*)malloc(n * sizeof(int));
	if (t1 == NULL) {
		fprintf(stderr, "Nieudało się zaalokwać pamięci dla t1!\n");
		return -2;
	}

	int *t2 = (int*)malloc(n * sizeof(int));
	if (t2 == NULL) {
		fprintf(stderr, "Nie udało się zaalokować pamięci dla t2!\n");
		return -3;
	}

	srand(time(NULL));

	fill_array(t1, n);

	printf("=======================ZAWARTOŚĆ T1====================\n");
	for (int i = 0; i < n; i++)
		printf("t1[%d]=%d\n", i, t1[i]);

	int t1_min_pos;
	int t1_min = find_min(t1, n, &t1_min_pos);
	printf("\nMinimum: %d\tPołożenie: %d\n", t1_min, t1_min_pos);

	int t2_max_pos;
	int t2_max = find_max(t1, n, &t2_max_pos);
	printf("Maximum: %d\tPołożenie: %d\n", t2_max, t2_max_pos);

	memmove(t2, t1, n * sizeof(int));

	printf("\n=======================ZAWARTOŚĆ T2====================\n");
	for (int i = 0; i < n; i++)
		printf("t2[%d]=%d\n", i, t2[i]);

	free(t1);
	free(t2);
	return 0;
}

void fill_array(int *arr, int arr_len) {
	for (int i = 0; i < arr_len; i++)	
		arr[i] = rand() % 100;

	return;
}

int find_min(int *arr, int arr_len, int *pos) {
	int min = arr[0];
	*pos = -1;
	
	for (int i = 0; i < arr_len; i++) {
		if (arr[i] < min) {
			min = arr[i];
			*pos = i;
		}
	}

	return min;
}

int find_max(int *arr, int arr_len, int *pos) {
	int max = arr[0];
	*pos = -1;
	
	for (int i = 0; i < arr_len; i++) {
		if (arr[i] > max) {
			max = arr[i];
			*pos = i;
		}
	}

	return max;
}
