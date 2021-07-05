SOURCES = ./src/*.cpp

OBJ_NAME = game

all : $(SOURCES)
	g++ $(SOURCES) -w -lsfml-graphics -lsfml-window -lsfml-system -o $(OBJ_NAME)
