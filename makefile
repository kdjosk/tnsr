#makefile for tnsr program

tnsr : main.o tensor.o menu_handler.o
	g++ -o tnsr main.o tensor.o menu_handler.o

main.o : main.cpp
	g++ -c main.cpp

tensor.o : tensor.cpp tensor.h
	g++ -c tensor.cpp

menu_handler.o : menu_handler.cpp menu_handler.h
	g++ -c menu_handler.cpp 
.PHONY : clean
clean:
	-rm *.o
