all: build
build:
	g++ -lm -Wall -o main main.cpp
	./main
