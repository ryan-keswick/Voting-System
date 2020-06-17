#!/bin/sh

sed -i "s/_difficulty =.*/_difficulty = $1;/" src/BlockChain.cpp 
sed -i "s/int difficulty =.*/int difficulty = $1;/" src/Block.cpp 
touch src/BlockChain.cpp
touch src/Block.cpp
make
