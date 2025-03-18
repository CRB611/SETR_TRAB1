# Variáveis de configuração
BUILD_DIR = build
TARGET = $(BUILD_DIR)/main
SOURCES = main.c MyDLL.c
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)
CFLAGS = -g -Wall -O3
CC = gcc

# Alvo padrão
all: $(TARGET)

# Regra para criar a pasta build, se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regra para compilar cada fonte em um objeto na pasta build
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	
# Regra para limpar os arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

