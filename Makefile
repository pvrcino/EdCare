CC=gcc

SRC = src/sensor.c src/cuidador.c src/idoso.c src/lista.c src/edcare.c src/main.c

edcare: $(SRC)
	$(CC) -o $@ $^ -w -lm