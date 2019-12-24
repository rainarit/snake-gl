CC = g++

INC =	-I inc\
		-I sound/include

SRC =	Main.cpp\
		Game.cpp

GRAPH_LIB	= -lGL -lglut
SOUND_LIB	= -L "/usr/lib" sound/IRRKLANG_LINUX/libIrrKlang.so -pthread

LIBS = $(GRAPH_LIB) $(SOUND_LIB)

NAME = SNAKE

all:
	$(CC) $(SRC) -o $(NAME) $(INC) $(LIBS)
clean:
	rm -rf $(NAME)
