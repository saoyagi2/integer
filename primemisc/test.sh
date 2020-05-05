#!/bin/sh

. "../libtest.sh"

exectest "./emirp" ""
exectest "./emirp 2" ""
exectest "./emirp 2 10" ""
exectest "./emirp 2 100" "13 17 31 37 71 73 79 97"
exectest "./emirp 900 1000" "907 937 941 953 967 971 983 991"
exectest "./emirp 9900 10000" "9923 9931 9941 9967"

exectest "echo -n | ./palindromicprime" ""
exectest "(echo 2) | ./palindromicprime" "2"
exectest "(echo 11; echo 13) | ./palindromicprime" "11"
exectest "(echo 101; echo 103) | ./palindromicprime" "101"

exectest "echo -n | ./palindromicprime2" ""
exectest "(echo 2) | ./palindromicprime2" "2"
exectest "(echo 11; echo 2) | ./palindromicprime2" "11"
exectest "(echo 101; echo 2) | ./palindromicprime2" "101"

exectest "echo -n | ./primedigit" ""
exectest "(echo 2) | ./primedigit" "2 1"
exectest "(echo 2; echo 3) | ./primedigit" "2 1 3 1"
exectest "echo 11 | ./primedigit" "11 1"
exectest "echo 13 | ./primedigit" "13 2"

exectest "echo -n | ./primedigit2" ""
exectest "(echo 2) | ./primedigit2" "2 1"
exectest "(echo 2; echo 1) | ./primedigit2" "2 1 3 1"
exectest "echo 11 | ./primedigit2" "11 1"
exectest "echo 13 | ./primedigit2" "13 2"

exectest "echo -n | ./twinprime" ""
exectest "(echo 2; echo 3) | ./twinprime" ""
exectest "(echo 3; echo 5) | ./twinprime" "3 5"
exectest "(echo 7; echo 11) | ./twinprime" ""

exectest "echo -n | ./twinprime2" ""
exectest "(echo 2; echo 1) | ./twinprime2" ""
exectest "(echo 3; echo 2) | ./twinprime2" "3 5"
exectest "(echo 7; echo 4) | ./twinprime2" ""

exectest "echo -n | ./brotherprime" ""
exectest "(echo 2; echo 3) | ./brotherprime 4" ""
exectest "(echo 3; echo 5) | ./brotherprime 4" ""
exectest "(echo 7; echo 11) | ./brotherprime 4" "7 11"

exectest "echo -n | ./brotherprime2" ""
exectest "(echo 2; echo 1) | ./brotherprime2 4" ""
exectest "(echo 3; echo 2) | ./brotherprime2 4" ""
exectest "(echo 7; echo 4) | ./brotherprime2 4" "7 11"

exectest "./primegen" ""
exectest "./primegen 0 2 1 3" "0 1 NG 1 3 OK 2 5 OK 3 7 OK"
exectest "./primegen 1 1 41 3" "0 41 OK 1 43 OK 2 47 OK 3 53 OK"

exectest "./mersenne" ""
exectest "./mersenne 3" "OK"
exectest "./mersenne 4" "NG"
exectest "./mersenne 11" "NG"
exectest "./mersenne 13" "OK"

exectest "./fermat" ""
exectest "./fermat 4" "OK"
exectest "./fermat 5" "NG"
