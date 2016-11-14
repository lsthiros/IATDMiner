# Compiler variables
CC = clang++
CC_FLAGS = -g -Wall -std=c++11

# Project variables
EXECUTABLE_NAME = ShaCoreTest
SOURCES = main.cpp
OTHER_OBJECTS = ../obj_dir/Vsha_core__ALL.a verilated.a
EXT_LIB = 
LIB_DIR = .
INCLUDE = -I../obj_dir

# tput color constants
RED = 1
YELLOW = 3
GREEN = 2
TEAL = 6
MAGENTA = 5

# Verilator stuff
LIBVERILATOR_INCLUDE = $(shell pkg-config --cflags verilator)

# Generated variables (Don't change these)
LIBFLAGS = $(addprefix -l, $(EXT_LIB))
COMPILED_OBJECTS = $(SOURCES:.cpp=.o) 
OBJECTS = $(COMPILED_OBJECTS) $(OTHER_OBJECTS)
ALL_LIBS = 
ALL_INCLUDE = $(INCLUDE) $(LIBVERILATOR_INCLUDE)
# LINKER_FLAGS = -Wl,-R -Wl,$(LIB_DIR)

define colorecho
	-@tput setaf $2
	@echo $1
	-@tput sgr0
endef

all : $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME) : $(OBJECTS)
	$(call colorecho,"Linking $@",$(TEAL))
	$(CC) $(CC_FLAGS) $(LINKER_FLAGS) $(OBJECTS) $(LIBFLAGS) $(ALL_LIBS) -o $(EXECUTABLE_NAME)
	$(call colorecho,"Complete!",$(GREEN))

%.o : %.cpp
	$(call colorecho, "Compiling $<", $(MAGENTA))
	$(CC) $(CC_FLAGS) $(ALL_INCLUDE) -c $< -o $@

clean:
	$(call colorecho,"Cleaning all generated files...",$(TEAL))
	@rm -rf $(COMPILED_OBJECTS) $(EXECUTABLE_NAME)

