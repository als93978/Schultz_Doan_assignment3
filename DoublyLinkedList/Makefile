FLAGS = -g -Wall -O0 -pedantic-errors

compile: main

main: ItemType.cpp DoublyLinkedList.cpp Main.cpp
	g++ $(FLAGS) -o main ItemType.cpp DoublyLinkedList.cpp Main.cpp

run:
	./main

clean:
	rm main
