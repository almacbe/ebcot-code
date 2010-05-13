FLAGS= -Wall -pedantic
HEADERS  = -I./headers

ebcot: src/ebcot.cpp FichBits.o ImagenES.o
	g++ -o ebcot src/ebcot.cpp FichBits.o ImagenES.o $(FLAGS) $(HEADERS)

debug: src/ebcot.cpp FichBits.o ImagenES.o
	g++ -o ebcot src/ebcot.cpp FichBits.o ImagenES.o $(FLAGS) $(HEADERS) -g
	
FichBits.o:  src/FichBits.cpp headers/FichBits.h
	g++ -c src/FichBits.cpp $(FLAGS) $(HEADERS)

ImagenES.o: src/ImagenES.cpp headers/ImagenES.h
	g++ -c src/ImagenES.cpp $(FLAGS) $(HEADERS)
	
clean:
	rm -f *.o *~ ./src/*~ ./include/*~
