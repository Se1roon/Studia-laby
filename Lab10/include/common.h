#ifndef COMMON_H
#define COMMON_H

typedef struct stud {
	char *imie;
	char *nazwisko;
	int rok;
	char *adres;
	double stypendium;
	struct stud *n;
} STUDENT;

#endif
