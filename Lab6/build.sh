#!/bin/sh

if [ "$1" == "15" ]; then
	gcc -o ./bin/zad15 ./src/zad15.c ./src/common.c -I./include -std=c99 -Wall -Wextra

	if [ "$2" == "run" ]; then
		./bin/zad15 dane.txt 0 5
	fi
elif [ "$1" == "16" ]; then
	gcc -o ./bin/zad16 ./src/zad16.c ./src/common.c -I./include -std=c99 -Wall -Wextra

	if [ "$2" == "run" ]; then
		./bin/zad16 dane.txt nb
	fi
elif [ "$1" == "17" ]; then
	gcc -o ./bin/zad17 ./src/zad17.c ./src/common.c -I./include -std=c99 -Wall -Wextra

	if [ "$2" == "run" ]; then
		./bin/zad17 dane.txt 0 3
	fi
fi
