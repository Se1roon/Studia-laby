#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	100

int main(void) {
	int nums[SIZE];
	for (int i = 0; i < SIZE/2; i++) nums[i] = 10;
	for (int i = SIZE/2; i < SIZE; i++) nums[i] = 20;

	FILE *fd = fopen("zad4_output", "ab+");
	fwrite(nums, sizeof(int), SIZE, fd);

	memset(nums, 0, SIZE * sizeof(int));

	fseek(fd, 0, SEEK_SET);
	fread(nums, sizeof(int), SIZE, fd);
	
	for (int i = 0; i < SIZE; i++) printf("nums[%d] = %d\n", i, nums[i]);

	fclose(fd);
	return 0;
}
