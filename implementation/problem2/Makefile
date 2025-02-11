# Author: Hoai Dinh

PROJ := remove_dups

OBJ_DIR := ./obj

EXE  := $(PROJ)
SRCS := ${wildcard ./src/*.cpp}
OBJS := ${SRCS:./src/%.cpp=$(OBJ_DIR)/%.o}

CC := g++

all: $(EXE)

$(EXE): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) -g -o $@

$(OBJ_DIR): $(SRC)
	mkdir -p $(OBJ_DIR)

$(OBJS): $(OBJ_DIR)/%.o : ./src/%.cpp
	$(CC) -g -c $<
	mv *.o $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(EXE)