

CXX = g++




# use shell and find instead wildcard
SRC := $(shell find ./source/ -type f -name '*.cpp')
OBJ := $(SRC:%.cpp=%.o)
INC = "./include"

MAIN_SOURCE := $(wildcard *.cpp)
MAIN_SOURCE := $(MAIN_SOURCE:%.cpp=%)
all: ${OBJ}

%.o: %.cpp
	${CXX} -I${INC} -c $< -o $@

${MAIN_SOURCE}:${OBJ}
	@echo "Checking ..."
	@echo $<

clean:
	rm -rf ${OBJ}


