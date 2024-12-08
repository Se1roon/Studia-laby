#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


char litery[] = {'a',165,'b','c',134,'d','e',169,'f','g','h','i','j','k','l',136,'m','n',228,'o',162,
		'p','q','r','s',152,'t','u','v','w','x','y','z',190,171,'A',164,'B','C',143,'D','E',168,'F','G',
		'H','I','J','K','L',157,'M','N',227,'O',224,'P','Q','R','S',151,'T','U','V','W','X','Y','Z',189,
		141,' ','.',',','?',':','-','0','1','2','3','4','5','6','7','8','9','!','\0' };
	char *mors[] = { ".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--",".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.", "...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--"," ",".-.-.-","--..--","..--..","---...","-....-","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","!",0 };


typedef struct cli_options {
	bool decode;
	bool encode;
	char *src;
} OPTIONS;

void encode(char *src, int);
void decode(char *src, int);
int get_pos_normal(char c);
int get_pos_encoded(char *c, int);
void print_usage(char *argv[]);

int main(int argc, char *argv[]) {
	OPTIONS options = {0};
	char c;
	while ((c = getopt(argc, argv, "des:")) != -1) {
		switch (c) {
			case 'd':
				options.decode = true;
				break;
			case 'e':
				options.encode = true;
				break;
			case 's':
				options.src = optarg;
				break;
			case '?':
				print_usage(argv);
		}
	}

	if (!options.src) {
		printf("Please provide path to the file you want to de/encode!\n");
		print_usage(argv);
		return 0;
	}
	if (!options.encode && !options.decode) {
		printf("Please specify whether you want to encode or decode the file!\n");
		print_usage(argv);
		return 0;
	}

	int fd = open(options.src, O_RDONLY);
	struct stat srcf_stat;
	fstat(fd, &srcf_stat);

	char *buff = (char *)malloc(srcf_stat.st_size);
	read(fd, buff, srcf_stat.st_size);

	if (options.encode) encode(buff, srcf_stat.st_size);
	else if (options.decode) decode(buff, srcf_stat.st_size);

	free(buff);
	return 0;
}

void encode(char *src, int src_len) {
	int src_index = 0;
	char current_c;
	int c_pos = -1;
	do {
		current_c = src[src_index++];
		c_pos = get_pos_normal(current_c);

		printf("%s|", mors[c_pos]);
	} while (src_index < src_len - 1);
	printf("\n");
	
	return;
}

void decode(char *src, int src_len) {
	int src_index = 0;
	int encoded_part_len = 0;
	char *encoded_part = (char *)calloc(encoded_part_len, sizeof(char));
	char current_c;	
	int c_pos = -1;

	do {
		current_c = src[src_index++];
		if (current_c == '|') {
			c_pos = get_pos_encoded(encoded_part, encoded_part_len);
			printf("%c", litery[c_pos]);

			encoded_part_len = 0;
			free(encoded_part);
			encoded_part = (char *)calloc(encoded_part_len, sizeof(char));
		} else {
			encoded_part = (char *)realloc(encoded_part, (encoded_part_len + 1) * sizeof(char));
			encoded_part[encoded_part_len++] = current_c;
		}
	} while (src_index < src_len);

	printf("\n");

	return;
}

int get_pos_normal(char c) {
	for (int i = 0; i < 88; i++)
		if (litery[i] == c) return i;

	return -1;
}

int get_pos_encoded(char *c, int c_len) {
	for (int i = 0; i < 88; i++) {
		int l2 = strlen(mors[i]);
		if (strncmp(c, mors[i], (c_len > l2) ? c_len : l2) == 0) return i;
	}

	return -1;
}

void print_usage(char *argv[]) {
	printf("Usage: %s [-e | -d] -s <filepath>\n", argv[0]);
	printf("\t-e ~ encode\n\t-d ~ decode\n\t-s ~ filepath\n");
	return;
}
