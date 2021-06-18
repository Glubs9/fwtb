.PHONY: clean

BUILD ?= ./build
SRC ?= ./src

SRCS := $(shell find $(SRC) -name *.c)
OBJS := $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CFLAGS := -Iinclude -Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code
	
$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

fwtb: $(OBJS)
	cc -o $@ $^

all: fwtb

run: all
	./fwtb

clean:
	$(RM) -r build
	$(RM) fwtb
