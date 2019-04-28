#!/bin/bash
#compilation
gcc -std=c11 -O2 -lm -o monEXE tp3.c outils.c structure.c
#exécution
echo "5 2658455991569831744654692615953842177" \
 | timeout 360s /usr/bin/time -f "%Mk\t%E\t%x" ./monEXE \
 -d ASC -c FRAG12345678
#coup de balai
rm -f monEXE
