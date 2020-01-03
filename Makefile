CXX  = g++
EXEC = FEMALE
FLAGS= -O3


#<><><><><><><><><><><><><><><><><><><><><><><><>
# use shell to find files instead wildcard
#<><><><><><><><><><><><><><><><><><><><><><><><>
SRC := $(shell find ./source/ -type f -name '*.cpp')
OBJ := $(SRC:%.cpp=%.o)
INC := ./include

MAIN_SOURCE := $(wildcard *.cpp)
MAIN_SOURCE := $(MAIN_SOURCE:%.cpp=%)


LIBS := -llapack -lblas



.PHONY := all %.o ${MAIN_SOURCE}

all:   ${MAIN_SOURCE}
build: ${MAIN_SOURCE}
#<><><><><><><><><><><><><><><><><><><><><><><><>
# Link the code
#<><><><><><><><><><><><><><><><><><><><><><><><>
${MAIN_SOURCE}:${OBJ}
	@echo ""
	@echo "FLAGS : ${FLAGS}"
	@echo "Checking ..."
	@${CXX} ${FLAGS} -I${INC} -o ${EXEC} ${MAIN_SOURCE}.cpp ${OBJ} ${LIBS} 
#<><><><><><><><><><><><><><><><><><><><><><><><>
# Create Object files
#<><><><><><><><><><><><><><><><><><><><><><><><>
%.o: %.cpp
	@echo "Building .. $<"
	@${CXX} ${FLAGS} -I${INC} -c $< -o $@


clean:
	@echo "Removing files"
	@rm -rf ${OBJ}

cleanall:
	@rm -rf ${OBJ}
	@rm -rf ${EXEC}	
	
