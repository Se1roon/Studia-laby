#!/bin/sh

if [ "$1" == "10" ]; then
	if [ "$2" == "g" ]; then
		gcc -o ./bin/zad$1 ./src/zad$1.c -g -std=c99 -Wall -Wextra
	else	
		gcc -o ./bin/zad$1 ./src/zad$1.c -std=c99 -Wall -Wextra
	fi
fi

if [ "$1" == "11" ]; then
	if [ "$2" == "g" ]; then
		gcc -o ./bin/zad$1 ./src/zad$1.c -g -std=c99 -Wall -Wextra
	else
		gcc -o ./bin/zad$1 ./src/zad$1.c -std=c99 -Wall -Wextra
	fi;
fi

if [ "$1" == "12" ]; then
	if [ "$2" == "g" ]; then
		gcc -o ./bin/zad$1 ./src/zad$1.c -g -std=c99 -Wall -Wextra
	else
		gcc -o ./bin/zad$1 ./src/zad$1.c -std=c99 -Wall -Wextra
	fi;
fi



# i am not good in bash
if [ "$2" == "run" ]; then
	./bin/zad$1
elif [ "$3" == "run" ]; then
	./bin/zad$1
fi

