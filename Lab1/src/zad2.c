#include <stdio.h>

#define VER	2
#define Y	2137
#define ADD(a, b) a+b

int main(void) {
#if VER == 2
	int x;
	int y = 2137;

	x = y;
	x = ADD(x, 3);
	x *= 2;
#else 
	int x, y;
	printf("Początkowa wartość: x=%d, y=%d\n", x, y);

	y = 2137;
	x = y;

	x += 3;
	x *= 2;
#endif

	printf("Końcowa wartość: x=%d, y=%d\n", x, y);

	printf("Data: %s\n", __DATE__);
	printf("Godzina: %s\n", __TIME__);

	return 0;
}
