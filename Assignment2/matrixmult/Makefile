.PHONY: benchmark clean tar

CC=gcc
GOTO=-lblas

#
# Compiler and compiler flags
#
#CC = gcc
#CC = icc
CFLAGS = -Wall -pedantic -O3 -std=gnu99 
#CFLAGS = -Wall -O3 -std=gnu99
#CFLAGS = -Wall -g -O0 -std=gnu99

#
# Linker flags to resolve calls from external libraries
#

#GOTO = -mkl -static-intel
LDLIBS = $(GOTO)
 


EXECS = basic_dgemm blas_dgemm blocked_dgemm 

all: $(EXECS)

basic_dgemm: matmul.c basic_dgemm.c
blocked_dgemm: matmul.c blocked_dgemm.c
blas_dgemm: matmul.c blas_dgemm.c
blocked_dgemm: CFLAGS+=-funroll-loops

timing.ps: $(EXECS)
	./sbatch matrixmult.sbatch matrixmult.sh
	
benchmark: timing.ps $(EXECS)

clean:
	rm -f $(EXECS) *.o *.ps .matmul.data_* *.data *.out

tar:
	cd ../; tar -cf matrixmult.tar matrixmult/*

