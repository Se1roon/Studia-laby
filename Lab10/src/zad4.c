#include <stdio.h>

struct liczba8 {
	__int8_t a;
	__int8_t b;
};

union liczba16 {
	struct liczba8 jeden;
	__int16_t dwa;
};

int main(void) {
	union liczba16 L;
	L.jeden.a = 127;
	L.jeden.b = 255;

	printf("A (10): %i\n", L.jeden.a);
	printf("A (16): %x\n\n", L.jeden.a);
	printf("B (10): %i\n", L.jeden.b);
	printf("B (16): %x\n\n", L.jeden.b);
	printf("(10): %i\n", L.dwa);
	printf("(16): %x\n", L.dwa);

	return 0;
}
