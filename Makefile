.PHONY: clean

BUILD ?= ./build
SRC ?= ./src

SRCS := $(shell find $(SRC) -name *.c)
OBJS := $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	cc -c $< -o $@

fwtb: $(OBJS)
	cc -o $@ $^

all: fwtb

run: all
	./fwtb

clean:
	$(RM) -r build
	$(RM) fwtb
