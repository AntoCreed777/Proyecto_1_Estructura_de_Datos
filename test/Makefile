# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -I ../Con_Cola/include
OBJ_DIR = build
TARGET = main.out
TEST_TARGET = test.out

# Archivos fuente del proyecto, excepto main.cpp
SRC_DIR = ../Con_Cola/src
SOURCES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Archivo fuente del test
TEST_SRC = test1.cpp
TEST_OBJ = $(OBJ_DIR)/test1.o

.PHONY: all clean run debug test test-run memoria

# Compilar el programa principal
all: $(TARGET)

$(TARGET): $(OBJECTS) $(SRC_DIR)/main.cpp
	@echo "Compilando el programa..."
	@$(CXX) $(OBJECTS) $(SRC_DIR)/main.cpp -o $(TARGET) $(CXXFLAGS)

# Compilar test (sin main.cpp, con test1.cpp)
test: $(OBJECTS) $(TEST_OBJ)
	@echo "Compilando el test..."
	@$(CXX) $(OBJECTS) $(TEST_OBJ) -o $(TEST_TARGET) $(CXXFLAGS)

# Ejecutar test
test-run: test
	@echo "Ejecutando test...\n"
	@./$(TEST_TARGET) < ./testeo/test4.txt

# Compilar archivos fuente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

# Compilar archivo de test
$(OBJ_DIR)/test1.o: $(TEST_SRC) | $(OBJ_DIR)
	@echo "Compilando test $<..."
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

# Crear build/
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Ejecutar programa principal
run: $(TARGET)
	@echo "Ejecutando el programa...\n"
	@./$(TARGET) < ./testeo/test4.txt

# Debug principal
debug: $(TARGET)
	@gdb ./$(TARGET)

# Debug test
debug-test: test
	@gdb ./$(TEST_TARGET)

# Valgrind test
memoria-test: test
	@valgrind --leak-check=full --track-origins=yes ./$(TEST_TARGET)

# Limpiar todo
clean:
	@rm -rf $(OBJ_DIR) $(TARGET) $(TEST_TARGET)
