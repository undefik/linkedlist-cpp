all: build
build:
	g++ -g -lm -Wall -o main main.cpp
	./main
