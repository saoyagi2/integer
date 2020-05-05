#!/bin/sh

. "../libtest.sh"

exectest "./prime1" ""
exectest "./prime1" ""
exectest "./prime1 2" ""
exectest "./prime1 2 10" "2 3 5 7"
exectest "./prime1 100 110" "101 103 107 109"
exectest "./prime1 1000 1010" "1009"
exectest "./prime1 9900 9999" "9901 9907 9923 9929 9931 9941 9949 9967 9973"

exectest "./prime2 | head -5" "2 3 5 7 11"
exectest "./prime2 | tail -5" "99999931 99999941 99999959 99999971 99999989"

exectest "./prime3" ""
exectest "./prime3 2" ""
exectest "./prime3 2 10" "2 3 5 7"
exectest "./prime3 100 110" "101 103 107 109"
exectest "./prime3 1000 1010" "1009"
exectest "./prime3 9900 9999" "9901 9907 9923 9929 9931 9941 9949 9967 9973"

exectest "./gmpprime1" ""
exectest "./gmpprime1 2" ""
exectest "./gmpprime1 2 10" "2 3 5 7"
exectest "./gmpprime1 100 110" "101 103 107 109"
exectest "./gmpprime1 1000 1010" "1009"
exectest "./gmpprime1 9900 9999" "9901 9907 9923 9929 9931 9941 9949 9967 9973"
