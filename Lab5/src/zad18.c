#include <stdio.h>
#include <string.h>

void switch_elements(int *array, int array_len);

int main(void) {
	int nums[] = {1, 20, -10, 20, 11, 21, 0, 21, -22};
	int nums_len = 9;

	printf("BEFORE\n");
	for (int i = 0; i < nums_len; i++)
		printf("%d, ", nums[i]);
	printf("\n");

	switch_elements(nums, nums_len);

	printf("\nAFTER\n");
	for (int i = 0; i < nums_len; i++)
		printf("%d, ", nums[i]);
	printf("\n");

	return 0;
}

void switch_elements(int *array, int array_len) {
	if (array_len <= 1) return;
		
	int temp1;
	int temp2;
	for (int i = 1; i + 1 < array_len; i++) {
		if (i == 1) {
			temp1 = array[i + 1];
			array[i + 1] = array[i];
		} else {
			temp2 = array[i + 1];
			array[i + 1] = temp1;
			temp1 = temp2;
		}
	}

	temp2 = array[0];
	array[0] = temp1;
	array[1] = temp2;

	return;
}

