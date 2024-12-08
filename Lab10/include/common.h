#ifndef COMMON_H
#define COMMON_H

typedef struct student {
	char *imie;
	char *nazwisko;
	int rok;
	char *adres;
	double stypendium;
	struct student *next;
} STUDENT;

char *get_line(FILE *);

#endif
