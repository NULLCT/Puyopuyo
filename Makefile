SRCPATH=src
BUILDPATH=build
CC=clang++
FLAGS=-std=c++17
INCLUDE=-I ./imgui-sfml -I ./imgui

sfmlapp: $(BUILDPATH)/main.o
	$(CC) $(BUILDPATH)/main.o -o sfmlapp -lsfml-graphics -lsfml-window -lsfml-system

$(BUILDPATH)/main.o: $(SRCPATH)/main.cpp
	-mkdir $(BUILDPATH)
	$(CC) -c $(SRCPATH)/main.cpp -o $(BUILDPATH)/main.o $(INCLUDE)


run:
	make
	./sfmlapp

clean:
	rm sfmlapp
	rm build/*
