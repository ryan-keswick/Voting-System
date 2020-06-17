#!/bin/sh

egrep Data debugChain.txt |
egrep -v Genesis |
cut -d' ' -f2 |
sort |
uniq -c
