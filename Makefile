# 컴파일러 설정
CC = g++
CXXFLAGS = -Wall -std=c++11

# 파일 설정
TARGET = main
OBJ_DIR = obj
SRC_DIR = src
OBJS = $(OBJ_DIR)/GF_field.o $(OBJ_DIR)/main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/GF_field.o: $(SRC_DIR)/GF_field.cc $(SRC_DIR)/GF_field.hh
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/GF_field.cc -o $(OBJ_DIR)/GF_field.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cc $(SRC_DIR)/GF_field.hh
	$(CC) $(CXXFLAGS) -c $(SRC_DIR)/main.cc -o $(OBJ_DIR)/main.o

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

rebuild: clean all
