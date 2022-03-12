CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: main

clean:
	rm main Message.o Product.o User.o TextUI.o

main: main.cpp Message.o Product.o User.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp  Message.o Product.o User.o TextUI.o -o main

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

Product.o: Product.cpp
	$(CXX) $(CXXFLAGS) -c Product.cpp

Message.o: Message.cpp
	$(CXX) $(CXXFLAGS) -c Message.cpp

User.o: User.cpp
	$(CXX) $(CXXFLAGS) -c User.cpp