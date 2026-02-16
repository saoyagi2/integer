#!/bin/sh

. "../libtest.sh"

exectest "./perfect 0 0" "bad parameter"
exectest "./perfect 2 10" "6"
exectest "./perfect 2 30" "6 28"

exectest "./perfectarray 0 0" "bad parameter"
exectest "./perfectarray 2 10" "6"
exectest "./perfectarray 2 30" "6 28"

exectest "./gmpperfectarray 0 0" "bad parameter"
exectest "./gmpperfectarray 2 10" "6"
exectest "./gmpperfectarray 2 30" "6 28"

exectest "./multiplyperfectarray 0 0" "bad parameter"
exectest "./multiplyperfectarray 2 10" "1 6"
exectest "./multiplyperfectarray 2 1000" "1 6 1 28 2 120 1 496 2 672"

exectest "./gmpmultiplyperfectarray 0 0" "bad parameter"
exectest "./gmpmultiplyperfectarray 2 10" "1 6"
exectest "./gmpmultiplyperfectarray 2 1000" "1 6 1 28 2 120 1 496 2 672"
