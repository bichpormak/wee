all: cw clean

cw: main.o processing_text.o repeat_words.o repeat_numbers.o sorted_sentence.o
	gcc main.o processing_text.o repeat_words.o repeat_numbers.o sorted_sentence.o -o cw

main.o: main.c processing_text.h struct.h
	gcc -c main.c

processing_text.o: processing_text.c processing_text.h struct.h
	gcc -c processing_text.c

repeat_words.o: repeat_words.c repeat_words.h processing_text.h
	gcc -c repeat_words.c

repeat_numbers.o: repeat_numbers.c repeat_numbers.h processing_text.h
	gcc -c repeat_numbers.c

sorted_sentence.o: sorted_sentence.c sorted_sentence.h processing_text.h
	gcc -c sorted_sentence.c

clean:
	find . -name "*.o" ! -name "cw.o" -type f -exec rm -f {} +