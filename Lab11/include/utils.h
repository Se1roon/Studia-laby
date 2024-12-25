#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#include "common.h"

void clean_student(STUDENT *s);
STUDENT *read_student(FILE *f);
char *get_line(FILE *f);

#endif
