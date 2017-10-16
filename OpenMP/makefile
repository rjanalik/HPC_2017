all: pi0

pi0: pi0.c
	gcc -O3 -fopenmp $^ -o $@

pi1: pi1.c
	gcc -O3 -fopenmp $^ -o $@

pi2: pi2.c
	gcc -O3 -fopenmp $^ -o $@

clean:
	rm -rf pi{0,1,2}

