CXX := clang++
SFML_PREFIX := $(shell brew --prefix sfml)

CPPFLAGS := -I$(SFML_PREFIX)/include
CXXFLAGS := -std=c++17 -Wall -Wextra -g
LDFLAGS := -L$(SFML_PREFIX)/lib -Wl,-rpath,$(SFML_PREFIX)/lib
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system

TARGET := build/mandelbrot
SOURCES := $(wildcard src/*.cpp)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES) Makefile
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) -o $@ $(LDFLAGS) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)