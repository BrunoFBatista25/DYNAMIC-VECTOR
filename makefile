# ================================================
# Makefile para Vector Dinâmico em C
# ================================================

# Configurações do compilador
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -pedantic -O2
INCLUDES := -Iinclude -Isrc

# Nome do executável
TARGET  := vector_test

# Diretórios
SRC_DIR := src
TEST_DIR := tests

# Arquivos fonte
SRC := $(SRC_DIR)/vector.c
TEST_SRC := $(TEST_DIR)/main.c

# Regra principal
all: $(TARGET)

# Compilação do executável
$(TARGET): $(TEST_SRC) $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Limpar arquivos gerados
clean:
	rm -f $(TARGET) *.o

# Rodar o teste
run: $(TARGET)
	./$(TARGET)

# Rodar com Valgrind (para verificar vazamentos de memória)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Remover tudo e recompilar
rebuild: clean all

.PHONY: all clean run valgrind rebuild