CC=gcc
CFLAGS= -lm
DEPS = helpers.h
OBJ = main.o helpers.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

moboard: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	
clean:
	rm moboard *.o
