FLAGS = -Wall -Wextra -ggdb 

all: scout

scout: scout.o main.o
	gcc $(FLAGS) scout.o main.o -o scout

scout.o: ./src/scout.c
	gcc $(FLAGS) -c ./src/scout.c

main.o: ./src/main.c
	gcc $(FLAGS) -c ./src/main.c

clean: 
	rm main.o scout.o scout
