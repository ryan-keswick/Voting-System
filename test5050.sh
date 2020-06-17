#!/bin/sh

n=1

while [ "$n" -le "$1" ]
do
	if [ $(( n%2 )) -eq 0 ]
	then
		echo "Roslin" | ./userTesting.exe
	else
		echo "Gaius" | ./userTesting.exe
	fi
	n=$(( n+1 ))
done
echo << EOF
