.PHONY: clean

BUILD ?= ./build
SRC ?= ./src

SRCS := $(shell find $(SRC) -name *.c)
OBJS := $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CFLAGS := -Iinclude -Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code
	
$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
<<<<<<< HEAD
	cc -Iinclude -c $< -o $@
=======
	cc $(CFLAGS) -c $< -o $@
>>>>>>> parent of ea9c4f5... removed all compiler flags, I couldn't find any documentation on them and they feel unecersarry, feel free to msg me to have a talk about this if you want but for now this makes usign the program much nicer

fwtb: $(OBJS)
	cc -o $@ $^

all: fwtb

run: all
	./fwtb

clean:
	$(RM) -r build
	$(RM) fwtb
