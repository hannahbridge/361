mp3: mp3.o
	gcc -g mp3.o -o mp3
mp3.o: mp3.c mp3.h
	gcc -c -g mp3.c
run: mp3
	./mp3
clean: 
	rm -f *.o mp3
