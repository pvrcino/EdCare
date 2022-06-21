CC=gcc

SRC = src/sensor.c src/cuidador.c src/idoso.c src/LHSES.c src/edcare.c

edcare: $(SRC)
	$(CC) -o $@ $^ -w -lm