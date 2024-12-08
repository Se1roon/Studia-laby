#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char *extract_word(char *src, char div_char, int position);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s <plik> <pozycja>\n", argv[0]);
		return 0;
	}

	char *filepath = argv[1];
	int position = atoi(argv[2]);

	int f = open(filepath, O_RDONLY);
	if (f < 0) {
		fprintf(stderr, "Nie udało się otworzyć pliku!\n");
		return -1;
	}

	struct stat f_stat;
	fstat(f, &f_stat);
	int file_size = f_stat.st_size;

	char *buff = (char *)malloc(file_size);
	read(f, buff, file_size);

	char *w = extract_word(buff, ':', position);
	printf("%s\n", w);

	free(w);
	free(buff);
	return 0;
}

char *extract_word(char *src, char div_char, int position) {
	/* Ta funkcja wybiera z ciągu słów rozdzielonych znakiem <div_char> słowo
	 * znajdujące się za <position> znakiem rozdzielającym (liczone od 0)
	 *
	 * ! Funkcja zwraca wskaźnik do obszaru pamięci, który musi zostać zwolniony przez użytkownika
	 *
	 * Przykład:
	 *  src = "przykład:działania:funkcji"
	 *  div_char = ":"
	 *  position = 1 (słowo po drugim dwukropku)
	 *
	 *  output = "funkcji"
	 */
	int out_word_len = 0;
	char *out_word = (char *)calloc(out_word_len, sizeof(char));

	int should_read = 0;
	int index = 0;
	int div_count = 0;
	char current_char;
	while ((current_char = src[index]) != '\0') {
		if (current_char == div_char && should_read) break;
		if (current_char == div_char) div_count++;
		if (div_count == position) should_read = 1;

		if (should_read && current_char != ':') {
			out_word = (char *)realloc(out_word, (out_word_len + 1) * sizeof(char));
			out_word[out_word_len++] = current_char;
		}
	
		index++;
	}
	out_word = (char *)realloc(out_word, (out_word_len + 1) * sizeof(char));
	out_word[out_word_len] = '\0';

	return out_word;
}
