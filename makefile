CXX = g++
BIN = bin
SRC_DIR = src
SRC = $(shell find $(SRC_DIR) -name '*.cc')
LIB_DIR = -Llib
INCLUDE = -Iinclude
TEST_DIR = test
STD = -std=c++17
OUT = llibasync_task_cpp.a
LIB = -pthread

all:
	$(CXX) $(SRC) -c $(INCLUDE) $(LIB_DIR) $(LIB) $(STD) -O3;mv *.o bin; ar rscv $(OUT) bin/*;rm ./bin/*;mv $(OUT) $(BIN)

test:
	$(CXX) $(SRC) $(TEST_DIR)/$(main).cc -o $(BIN)/$(main) $(LIB_DIR) $(LIB) $(STD) $(INCLUDE) -O3
	
