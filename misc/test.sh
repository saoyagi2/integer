#!/bin/sh

. "../libtest.sh"

exectest "./pythagoras 0 0" "bad parameter"
exectest "./pythagoras 2 10" "3 4 5"
exectest "./pythagoras 10 20" "6 8 10 5 12 13 9 12 15 8 15 17"

exectest "./collatz 0 0" "bad parameter"
exectest "./collatz 2 100" ""

exectest "./goldbach 5 5" "bad parameter"
exectest "./goldbach 6 100" ""

exectest "./ogr 1 " "bad parameter"
exectest "./ogr 2" "0-1 1 nodes"
exectest "./ogr 3" "0-1-3 0-2-3 2 nodes"

exectest "./ogr2 1 " "bad parameter"
exectest "./ogr2 2" "0-1 0 nodes"
exectest "./ogr2 3" "0-1-3 0-2-3 3 nodes"
