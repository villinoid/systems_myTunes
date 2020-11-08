all: main.o song.o
	gcc -o main main.o song.o
	
main.o: main.c song.h
	gcc -c main.c
	
song.o: song.h
	gcc -c song.c

run: 
	./main
	
clean:
	rm *.o