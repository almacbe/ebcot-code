FLAGS= -Wall -pedantic
HEADERS  = -I./headers

ebcot: src/ebcot.cpp fichbits.o imagenes.o
	g++ ebcot src/ebcot.cpp fichbits.o imagenes.o $(FLAGS) $(HEADERS)
	
fichbits.o:  src/FichBits.cpp headers/FichBits.h
	g++ -c src/FichBits.cpp $(FLAGS) $(HEADERS)

imagenes.o: src/ImagenES.cpp headers/ImagenES.h
	g++ -c src/ImagenES.cpp $(FLAGS) $(HEADERS)
	
clean:
	rm -f *.o *~ ./src/*~ ./include/*~