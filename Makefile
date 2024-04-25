#################################################
# MAKEFILE
#################################################

BIN     		:= bin
SRC     		:= src
BUILD				:= build
INCLUDE 		:= include
LIB     		:= lib
LIBRARIES   :=

EXECUTABLE  := run
PARAMS    	:= -size 5 -ord incrDec 0.5 -init ramdom -trace y
PARAMSOPEN  := -size 5 -ord incrDec 0.5 -init file data1.txt -trace y

SOURCES := $(wildcard $(SRC)/*.cc)
OBJS	:= $(patsubst $(SRC)/%.cc,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean base

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L $(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src

run:
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) 

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*

open:
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS)