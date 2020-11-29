CC = gcc
CFLAGS = -c -Wall
SRC_DIR= src
CONSTANTS = $(addprefix $(SRC_DIR)/constant/, *.h)

ARRAY_C = $(addprefix $(SRC_DIR)/array/, array.c)
ARRAY_H = $(addprefix $(SRC_DIR)/array/, array.h)
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

array.o: $(ARRAY_C) $(ARRAY_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(ARRAY_C)

jam.o: $(JAM_C) $(JAM_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(JAM_C) 

list.o: $(LIST_C) $(LIST_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/linkedlist/, list.c)

matrix.o: $(MATRIX_C) $(MATRIX_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/matrix/, matrix.c) 

material.o: $(MATERIAL_C) $(MATERIAL_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/material/, material.c) 

point.o: $(PO_C) $(PO_H) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/point/, point.c)  

stack.o: $(addprefix $(SRC_DIR)/stack/, stack.c) $(addprefix $(SRC_DIR)/stack/, stack.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/stack/, stack.c) 

tree.o: $(addprefix $(SRC_DIR)/tree/, tree.c) $(addprefix $(SRC_DIR)/tree/, tree.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/tree/, tree.c)  

mesinkar.o: $(addprefix $(SRC_DIR)/word/, mesinkar.c) $(addprefix $(SRC_DIR)/word/, mesinkar.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/word/, mesinkar.c)

standar: array.o jam.o list.o matrix.o point.o stack.o tree.o mesinkar.o material.o
	
# ADT tingkatan
# visitor - jam , stack
# queue - visitor
# material
# wahana - tree , material , queue
# map - wahana , material

visitor.o: $(addprefix $(SRC_DIR)/jam/, jam.c) $(addprefix $(SRC_DIR)/jam/, jam.h) $(addprefix $(SRC_DIR)/visitor/, visitor.c) $(addprefix $(SRC_DIR)/visitor/, visitor.h) $(addprefix $(SRC_DIR)/stack/, stack.c) $(addprefix $(SRC_DIR)/stack/, stack.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/visitor/, visitor.c) 

graph.o: $(addprefix $(SRC_DIR)/point/, point.c) $(addprefix $(SRC_DIR)/point/, point.h) $(addprefix $(SRC_DIR)/graph/, graph.c) $(addprefix $(SRC_DIR)/graph/, graph.h) $(addprefix $(SRC_DIR)/matrix/, matrix.c) $(addprefix $(SRC_DIR)/matrix/, matrix.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/graph/, graph.c) $(addprefix $(SRC_DIR)/point/, point.c) $(addprefix $(SRC_DIR)/matrix/, matrix.c) 

arraymat.o: $(addprefix $(SRC_DIR)/material/, material.c) $(addprefix $(SRC_DIR)/material/, material.h) $(addprefix $(SRC_DIR)/array/, arraymat.c) $(addprefix $(SRC_DIR)/array/, arraymat.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/array/, arraymat.c) $(addprefix $(SRC_DIR)/material/, material.c)

queue.o: $(addprefix $(SRC_DIR)/jam/, jam.c) $(addprefix $(SRC_DIR)/jam/, jam.h) $(addprefix $(SRC_DIR)/visitor/, visitor.c) $(addprefix $(SRC_DIR)/visitor/, visitor.h) $(addprefix $(SRC_DIR)/stack/, stack.c) $(addprefix $(SRC_DIR)/stack/, stack.h) $(addprefix $(SRC_DIR)/queue/, queue.c) $(addprefix $(SRC_DIR)/queue/, queue.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/queue/, queue.c)

wahana.o: $(addprefix $(SRC_DIR)/wahana/, wahana.c) $(addprefix $(SRC_DIR)/wahana/, wahana.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/wahana/, wahana.c)

# TODO error harus bareng ama main keaknya
mesinkata.o: $(addprefix $(SRC_DIR)/word/, mesinkar.c) $(addprefix $(SRC_DIR)/word/, mesinkar.h) $(addprefix $(SRC_DIR)/word/, mesinkata.c) $(addprefix $(SRC_DIR)/word/, mesinkata.h) $(CONSTANTS)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/word/, mesinkata.c) $(addprefix $(SRC_DIR)/word/, mesinkar.c)

tingkatan: graph.o arraymat.o

all: standar

.PHONY: clean all

clean:
	-rm *.o *.gcda *.gcno