#!/bin/sh

. "../libtest.sh"

exectest "./yuuai 0 0" "bad parameter"
exectest "./yuuai 2 10000" "220 284 1184 1210 2620 2924 5020 5564 6232 6368"

exectest "./yuuaiarray 0 0" "bad parameter"
exectest "./yuuaiarray 2 10000" "220 284 1184 1210 2620 2924 5020 5564 6232 6368"

exectest "./konyaku 0 0" "bad parameter"
exectest "./konyaku 2 10000" "48 75 140 195 1050 1925 1575 1648 2024 2295 5775 6128 8892 16587 9504 20735"

exectest "./konyakuarray 0 0" "bad parameter"
exectest "./konyakuarray 2 10000" "48 75 140 195 1050 1925 1575 1648 2024 2295 5775 6128 8892 16587 9504 20735"

exectest "./syakou 0 0" "bad parameter"
exectest "./syakou 12496 12497" "12496 14288 15472 14536 14264"

exectest "./syakouarray 0 0" "bad parameter"
exectest "./syakouarray 12496 12497" "12496 14288 15472 14536 14264"
