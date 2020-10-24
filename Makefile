CC = gcc
CFLAGS = -c -Wall
SRC_DIR= src
SRC_ADT_FILES = $(addprefix $(SRC_DIR)/adt/, *.c)
SRC_GAME_FILES = $(addprefix $(SRC_DIR)/game/, *.c)

suatuadt.o:  $(SRC_ADT_FILES) $(addprefix $(SRC_DIR)/, adt.h)
	$(CC) $(CFLAGS) $(SRC_ADT_FILES)

suatuadt2.o: $(SRC_ADT_FILES) $(addprefix $(SRC_DIR)/, adt2.h)
	$(CC) $(CFLAGS) $(SRC_ADT_FILES)

program: suatuadt.o suatuadt2.o
	$(CC) suatuadt.o suatuadt2.o -o program

.PHONY: clean all

clean:
	-rm *.o *.gcda *.gcno