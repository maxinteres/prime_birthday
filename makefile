CC = gcc
TAR = prime_birthday
OBJ = prime_birthday.o prime.o mystack.o bitmap.o

$(TAR):$(OBJ)
	$(CC) $^ -o $@ -lm

%.o:%.c
	$(CC) $< -c

.PHONY:clean
clean:
	rm -f *.o
