CC = gcc
CFLAGS = -c -Wall
SRC_DIR= src
CONSTANTS = $(addprefix $(SRC_DIR)/constant/, *.h)

ARRAY_C = $(addprefix $(SRC_DIR)/array/, array.c)
ARRAY_H = $(addprefix $(SRC_DIR)/array/, array.h)
ARRAYMAT_C = $(addprefix $(SRC_DIR)/array/, arraymat.c)
ARRAYMAT_H = $(addprefix $(SRC_DIR)/array/, arraymat.h)
JAM_C = $(addprefix $(SRC_DIR)/jam/, jam.c)
JAM_H =	$(addprefix $(SRC_DIR)/jam/, jam.h)
LIST_C = $(addprefix $(SRC_DIR)/linkedlist/, list.c) 
LIST_H = $(addprefix $(SRC_DIR)/linkedlist/, list.h)
MATRIX_C = $(addprefix $(SRC_DIR)/matrix/, matrix.c)
MATRIX_H = $(addprefix $(SRC_DIR)/matrix/, matrix.h)
MATERIAL_C = $(addprefix $(SRC_DIR)/material/, material.c) 
MATERIAL_H = $(addprefix $(SRC_DIR)/material/, material.h)
POINT_C = $(addprefix $(SRC_DIR)/point/, point.c)
POINT_H = $(addprefix $(SRC_DIR)/point/, point.h)
TREE_C = $(addprefix $(SRC_DIR)/tree/, tree.c)
TREE_H = $(addprefix $(SRC_DIR)/tree/, tree.h)
STACK_C = $(addprefix $(SRC_DIR)/stack/, stack.c)
STACK_H = $(addprefix $(SRC_DIR)/stack/, stack.h)
MESINKAR_H = $(addprefix $(SRC_DIR)/word/, mesinkar.h)
MESINKAR_C = $(addprefix $(SRC_DIR)/word/, mesinkar.c)
MESINKATA_H = $(addprefix $(SRC_DIR)/word/, mesinkata.h)
MESINKATA_C = $(addprefix $(SRC_DIR)/word/, mesinkata.c)
WAHANA_C = $(addprefix $(SRC_DIR)/wahana/, wahana.c)
WAHANA_H = $(addprefix $(SRC_DIR)/wahana/, wahana.h)
QUEUE_C = $(addprefix $(SRC_DIR)/queue/, queuelist.c)
QUEUE_H = $(addprefix $(SRC_DIR)/queue/, queuelist.h)
GRAPH_C = $(addprefix $(SRC_DIR)/graph/, graph.c)
GRAPH_H = $(addprefix $(SRC_DIR)/graph/, graph.h)
MAP_C = $(addprefix $(SRC_DIR)/map/, map.c)
MAP_H = $(addprefix $(SRC_DIR)/map/, map.h)
ACTIONMANAGER_C = $(addprefix $(SRC_DIR)/game/, actionmanager.c)
ACTIONMANAGER_H = $(addprefix $(SRC_DIR)/game/, actionmanager.h)
STORAGEMANAGER_C = $(addprefix $(SRC_DIR)/game/, storagemanager.c)
STORAGEMANAGER_H = $(addprefix $(SRC_DIR)/game/, storagemanager.h)
GAME_C = $(addprefix $(SRC_DIR)/game/, game.c)
GAME_H = $(addprefix $(SRC_DIR)/game/, game.h)
RUN_C = $(addprefix $(SRC_DIR)/, driver.c)

array.o: $(ARRAY_C) $(ARRAY_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(ARRAY_C)

jam.o: $(JAM_C) $(JAM_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(JAM_C) 

list.o: $(LIST_C) $(LIST_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(LIST_C)

matrix.o: $(MATRIX_C) $(MATRIX_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(MATRIX_C) 

material.o: $(MATERIAL_C) $(MATERIAL_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(MATERIAL_C) 

point.o: $(POINT_C) $(POINT_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(POINT_C)  

stack.o: $(STACK_C) $(STACK_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(STACK_C) 

tree.o:  $(TREE_C) $(TREE_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(TREE_C) 

mesinkar.o: $(MESINKAR_C) $(MESINKAR_H)
	$(CC) $(CFLAGS) $(MESINKAR_C)

mesinkata.o: $(MESINKATA_C) $(MESINKATA_H)
	$(CC) $(CFLAGS) $(MESINKATA_C)

queuelist.o: $(QUEUE_C) $(QUEUE_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(QUEUE_C)

graph.o: $(GRAPH_C) $(GRAPH_H)
	$(CC) $(CFLAGS) $(GRAPH_C)

arraymat.o: $(ARRAYMAT_C) $(ARRAYMAT_H)
	$(CC) $(CFLAGS) $(ARRAYMAT_C)

wahana.o: $(WAHANA_H) $(WAHANA_C)
	$(CC) $(CFLAGS) $(WAHANA_C)

map.o: $(MAP_H) $(MAP_C)
	$(CC) $(CFLAGS) $(MAP_C)

actionmanager.o: $(ACTIONMANAGER_H) $(ACTIONMANAGER_C)
	$(CC) $(CFLAGS) $(ACTIONMANAGER_C)

storagemanager.o: $(STORAGEMANAGER_H) $(STORAGEMANAGER_C)
	$(CC) $(CFLAGS) $(STORAGEMANAGER_C)

game.o: $(GAME_H) $(GAME_C)
	$(CC) $(CFLAGS) $(GAME_C)

driver.o: $(RUN_C)
	$(CC) $(CFLAGS) $(RUN_C)

all: array.o jam.o list.o matrix.o material.o point.o tree.o stack.o mesinkar.o mesinkata.o queuelist.o graph.o arraymat.o wahana.o map.o actionmanager.o storagemanager.o game.o mesinkar.o mesinkata.o driver.o

run: all
	$(CC) -Wall -o run array.o jam.o list.o matrix.o material.o point.o tree.o stack.o queuelist.o graph.o arraymat.o wahana.o map.o actionmanager.o storagemanager.o game.o mesinkar.o mesinkata.o driver.o
	./run

.PHONY: clean all

clean:
	-rm *.o *.gcda *.gcno