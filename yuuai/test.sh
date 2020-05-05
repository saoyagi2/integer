#!/bin/sh

. "../libtest.sh"

exectest "./yuuai | head -5" "220 284 1184 1210 2620 2924 5020 5564 6232 6368"

exectest "./konyaku | head -5" "48 75 140 195 1050 1925 1575 1648 2024 2295"

exectest "./syakou" ""
