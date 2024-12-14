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

typedef struct stud_d {
	char *imie;
	char *nazwisko;
	int rok;
	char *adres;
	double stypendium;
	struct stud_d *n;
	struct stud_d *p;
} STUDENT_D;

#endif
