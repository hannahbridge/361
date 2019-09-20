mp3.o: mp3.c mp3.h
	gcc -o mp3.o mp3.c mp3.h
run: mp3.o
	./mp3.o
clean: 
	rm -f *.o mp3
