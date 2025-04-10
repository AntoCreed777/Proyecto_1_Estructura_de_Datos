# Nombre del ejecutable
TARGET = salida.out

# Compilador
CXX = g++

# Opciones de compilación
CFLAGS = -I ./include -g -Wall

# Directorio para archivos objeto
OBJ_DIR = build

# Archivos fuente
SOURCES = ./src/main.cpp ./src/cola_mechon.cpp

# Archivos objeto (guardados en build/)
OBJECTS = $(patsubst ./src/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean run debug memoria

# Regla por defecto: compilar el programa
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $(TARGET) $(CFLAGS)

# Regla para compilar los archivos objeto y guardarlos en obj/
$(OBJ_DIR)/%.o: ./src/%.cpp | $(OBJ_DIR)
	@$(CXX) -c $< -o $@ $(CFLAGS)

# Crear el directorio obj si no existe
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Regla para ejecutar el programa
run: $(TARGET)
	@./$(TARGET)

# Regla para debuggear el programa
debug: $(TARGET)
	@gdb ./$(TARGET)

# Regla para investigar las fugas de memoria
memoria: $(TARGET)
	@valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	@rm -rf $(OBJ_DIR) $(TARGET)