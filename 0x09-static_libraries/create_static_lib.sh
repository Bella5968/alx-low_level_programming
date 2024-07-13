#!/bin/bash
gcc -Wall -pedantic -Wrror -Wextra -c *.c
ar -rc liball.a *.o
ranlib liball.a
