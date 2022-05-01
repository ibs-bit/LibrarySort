CXX = g++
CXXFLAGS = -g -Wall -Wextra

.PHONY : all
all : Library

Library : Library.cpp sLinkedList.o Utility.o sLinkedList.o Node.o Book.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Utility.o : Utility.cpp Utility.h sLinkedList.o Node.o Book.o
	$(CXX) $(CXXFLAGS) -c $^
	
sLinkedList.o : sLinkedList.cpp sLinkedList.h Node.o Book.o
	$(CXX) $(CXXFLAGS) -c $^

Node.o : Node.cpp Node.h Book.o
	$(CXX) $(CXXFLAGS) -c $^

Book.o : Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c $<


.PHONY : clean
clean :
	rm *.o Library
