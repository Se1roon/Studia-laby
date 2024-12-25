#include <stdio.h>

enum MY_INTERF_EN {
	INTERF_PUSH,
	INTERF_POP,
	INTERF_FIND_LASTNAME,
	INTERF_DISPLAY,
	INTERF_COUNT,
	INTERF_CLEAR,
	INTERF_STOP,
	INTERF_TOT
};

int main(void) {
	printf("INTERF_PUSH          = %d\n", INTERF_PUSH);
	printf("INTERF_POP           = %d\n", INTERF_POP);
	printf("INTERF_FIND_LASTNAME = %d\n", INTERF_FIND_LASTNAME);
	printf("INTERF_DISPLAY       = %d\n", INTERF_DISPLAY);
	printf("INTERF_COUNT         = %d\n", INTERF_COUNT);
	printf("INTERF_CLEAR         = %d\n", INTERF_CLEAR);
	printf("INTERF_STOP          = %d\n", INTERF_STOP);
	printf("INTERF_TOT           = %d\n", INTERF_TOT);

	return 0;
}
