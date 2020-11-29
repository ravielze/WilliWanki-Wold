CC = gcc
CFLAGS = -c -Wall
SRC_DIR= alstrokeded
SRC_ADT_FILES = $(addprefix $(SRC_DIR)/*/, *.c)
src_ADT_HEADERS = $(addprefix $(SRC_DIR)/adt/*/, *.h)
SRC_GAME_FILES = $(addprefix $(SRC_DIR)/game/*/, *.c)

adt: $(SRC_ADT_FILES) $(SRC_ADT_HEADERS)
	$(CC) $(CFLAGS) $(SRC_ADT_FILES)
# MASIH DIPIKIR :<

.PHONY: clean all

clean:
	-rm *.o *.gcda *.gcno