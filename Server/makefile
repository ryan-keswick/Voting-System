CC=g++
CFLAGS = -g -Wall

server: Block.o BlockChain.o main.o sha256.o 
	$(CC) $(CFLAGS) -o server Block.o BlockChain.o main.o sha256.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

Block.o: Block.cpp
	$(CC) $(CFLAGS) -c Block.cpp  

BlockChain.o: BlockChain.cpp
	$(CC) $(CFLAGS) -c BlockChain.cpp  

sha256.o: sha256/sha256.cpp
	$(CC) $(CFLAGS) -c sha256/sha256.cpp

clean:
	$(RM) server *.o