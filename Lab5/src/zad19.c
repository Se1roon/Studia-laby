#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int moje_strcmp(const char *, const char *);
char *moje_strcat(char *, const char *);
char *moje_strcpy(char *, const char *);

int main(void) {
	return 0;
}

char *moje_strcpy(char *dst, const char *src) {
	memcpy(dst, src, strlen(src) + 1);
	
	return dst;
}

char *moje_strcat(char *dst, const char *src) {
	memmove(&dst[strlen(dst)], src, strlen(src) + 1);

	return dst;
}

int moje_strcmp(const char *s1, const char *s2) {
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	int len = (s1_len >= s2_len) ? s1_len : s2_len;

	for (int i = 0; i < len; i++) {
		if (s1[i] < s2[i]) return -1;
		if (s1[i] > s2[i]) return 1;
	}

	return 0;
}
