BUILD_DIR = build
TARGET = $(BUILD_DIR)/prog.out

CFLAGS = -g -Wall -Wextra -std=c++2a
LFLAGS = -Wall -Wextra -std=c++2a

CXX = g++
CLANG_FORMAT = clang-format

SOURCE_DIR = src
INCLUDE_DIR = include
TEMPLATE_DIR = .

SOURCES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
HEADERS = $(wildcard include/bitlib/**/*.hpp) $(wildcard src/**/*.tpp)

.PRECIOUS: $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -I $(INCLUDE_DIR) -I $(TEMPLATE_DIR) -c $< -o $@

$(TARGET): $(OBJECTS) Makefile
	mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) $(LFLAGS) -o $@

.PHONY: clean build run format

build: $(TARGET)

run: build
	@$(TARGET)

debug: build
	gdb $(TARGET)

clean:
	rm -f src/*.o
	rm -f src/**/*.o
	rm -f $(TARGET)

format:
	$(CLANG_FORMAT) -i $(SOURCES) $(HEADERS)
