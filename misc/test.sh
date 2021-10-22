#!/bin/sh

. "../libtest.sh"

exectest "./pythagoras 2 10" "3 4 5"
exectest "./pythagoras 10 20" "6 8 10 5 12 13 9 12 15 8 15 17"

exectest "./collatz 2 100" ""

exectest "./collatz2 4 100" ""

exectest "./goldbach 6 100" ""

exectest "./goldbach2 6 100" ""

exectest "./gmpgoldbach2 6 100" ""

exectest "./ogr 2" "0-1 1 nodes"
exectest "./ogr 3" "0-1-3 0-2-3 2 nodes"

exectest "./ogr2 2" "0-1 0 nodes"
exectest "./ogr2 3" "0-1-3 0-2-3 3 nodes"
