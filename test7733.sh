#!/bin/sh

n=1

while [ "$n" -le "$1" ]
do
	if [ $(( n%3 )) -eq 0 ]
	then
		echo "Gaius" | ./userTesting.exe
	else
		echo "Roslin" | ./userTesting.exe
	fi
	n=$(( n+1 ))
done
echo << EOF
