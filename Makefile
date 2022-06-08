CC=gcc

CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic

SRC = src/sensor.c src/cuidador.c src/idoso.c src/LHSES.c src/edcare.c

edcare: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o edcare