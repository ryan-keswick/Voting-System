CC=g++
CFLAGS = -g -Wall

server: src/Block.o src/BlockChain.o src/user.o src/miner.o src/sha256/sha256.o src/Networking/listener.o src/Networking/talker.o src/userTesting.o
	$(CC) $(CFLAGS) -o miner.exe src/Block.o src/BlockChain.o src/miner.o src/sha256/sha256.o src/Networking/listener.o src/Networking/talker.o
	$(CC) $(CFLAGS) -o user.exe src/Block.o src/BlockChain.o src/user.o src/sha256/sha256.o src/Networking/listener.o src/Networking/talker.o
	$(CC) $(CFLAGS) -o userTesting.exe src/Block.o src/BlockChain.o src/userTesting.o src/sha256/sha256.o src/Networking/listener.o src/Networking/talker.o

user.o: user.cpp 
	$(CC) $(CFLAGS) -c src/user.cpp 

userTesting.o: userTesting.cpp 
	$(CC) $(CFLAGS) -c src/userTesting.cpp 

miner.o: miner.cpp 
	$(CC) $(CFLAGS) -c src/miner.cpp 

Block.o: Block.cpp
	$(CC) $(CFLAGS) -c src/Block.cpp  

BlockChain.o: BlockChain.cpp
	$(CC) $(CFLAGS) -c src/BlockChain.cpp  

sha256.o: src/sha256/sha256.cpp
	$(CC) $(CFLAGS) -c src/sha256/sha256.cpp 

talker.o: src/Networking/talker.cpp
	$(CC) $(CFLAGS) -c src/Networking/talker.cpp 

listener.o: src/Networking/listener.cpp
	$(CC) $(CFLAGS) -c src/Networking/listener.cpp 


clean:
	find . -name "*.o" -type f -delete	
	find . -name "*.exe" -type f -delete	
