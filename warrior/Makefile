TARGET = warrior

# Diretórios
MAKEFILE_DIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
SRC_DIR = $(MAKEFILE_DIR)src
INCLUDE_DIR = $(MAKEFILE_DIR)include
BUILD_DIR = $(MAKEFILE_DIR)build

# Compiladores
CC = g++
EMCC = em++

# Flags de compilação
LDFLAGS = -lGL -lglut -lGLU
CFLAGS = -Wall -O2 -I$(INCLUDE_DIR)
EMFLAGS = -O2 -I$(INCLUDE_DIR) -sLEGACY_GL_EMULATION --shell-file $(MAKEFILE_DIR)shell.html

# Busca todos os arquivos .cpp no diretório src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

all: native

native: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

wasm: $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(EMCC) $(SRC_FILES) $(EMFLAGS) -o $(BUILD_DIR)/$(TARGET).html

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean native wasm