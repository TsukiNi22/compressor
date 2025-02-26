##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Radar makefile de la ta
##

CC := gcc

TARGET := compressor
BUILD_DIR := .obj

W := -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow
W += -Wuninitialized -Wmaybe-uninitialized -Werror

DEBUG := -g -ggdb3

CPPFLAGS := -I ./include/
LDFLAGS := -lm
CFLAGS := $(W)

ifeq ($(d), t)
	CFLAGS := $(DEBUG)
else ifeq ($(d), o)
	CFLAGS += -O1
endif

GLOBAL :=	main.c \
			const.c \
			compressor.c \
			free_data.c

INIT :=		init/init_data.c \
			init/init_flag.c\
			init/flag/null.c \
			init/flag/help.c \
			init/flag/precision.c \
			init/flag/round.c \
			init/flag/calculate.c \
			init/flag/undo.c

BITS := 	bits_edit/bits_compressor.c \
			bits_edit/bits_decompressor.c

MAIN := 	execution_files/compress_files.c \
			execution_files/decompress_files.c \
			execution_files/calculate.c

FILES := $(GLOBAL) $(INIT) $(BITS) $(MAIN)
SRC := $(addprefix src/, $(FILES))
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c -o $@ $^

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f tests/*.o
	@rm -f *.gc*
	@rm -f vgcore.*

fclean: clean
	@rm -f $(TARGET)

.NOTPARALLEL:
re: fclean $(TARGET)

get_unregistered_files:
	@find src/ -name "*.c" | while read file; do \
        	echo "$(SRC)" | grep -q "$$file" || \
		echo "$$file" >> new_files_detected.txt; \
        done
	@if [ -f new_files_detected.txt ]; then \
                cat new_files_detected.txt | sed "s/src\///g"; \
                rm -f new_files_detected.txt; \
        fi

get_unknow_files:
	@for file in $(SRC); do \
            if [ ! -f "$$file" ]; then \
                echo "$$file" >> missing_files.txt; \
            fi; \
        done;
	@if [ -f missing_files.txt ]; then \
                cat missing_files.txt | sed "s/src\///g"; \
                rm -f missing_files.txt; \
        fi

.PHONY: all clean fclean re get_unregistered_files get_unknow_files
