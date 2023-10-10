CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

AmplifyMatrix: AmplifyMatrix.o FloatMatrix.o
	$(CC) -o AmplifyMatrix AmplifyMatrix.o FloatMatrix.o
