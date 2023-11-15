all: main.o processing_text.o repeat_words.o
	gcc main.o processing_text.o repeat_words.o -o cw

main.o: main.c processing_text.h struct.h
	gcc -c main.c

processing_text.o: processing_text.c processing_text.h struct.h
	gcc -c processing_text.c

repeat_words.o: repeat_words.c repeat_words.h
	gcc -c repeat_words.c