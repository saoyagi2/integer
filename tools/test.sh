#!/bin/sh

. "../libtest.sh"

exectest "(echo 2; echo 3; echo 5; echo 7) | ./primes2diff 4" "2 1 2 2"

exectest "(echo 2; echo 1; echo 2; echo 2) | ./diff2primes 4" "2 3 5 7"
