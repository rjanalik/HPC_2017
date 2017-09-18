/*
 * LAPACK test code
 *
 * Use header file obtainable from http://www.netlib.org/lapack/lapacke.h
 * or explicitly specify signature of the used routines, i.e. 
 * extern "C" void dgetrf_(int* dim1, int* dim2, double* a, \
 *                         int* lda, int* ipiv, int* info);
 * extern "C" void dgetrs_(char *TRANS, int *N, int *NRHS, double *A, \
 *                         int *LDA, int *IPIV, double *B, int *LDB, int *INFO );
 *
 * Compile using -llapack flag (see Makefile)
 *
 * 
 * Juraj Kardos
 * USI Lugano
 */

#include <iostream>
#include <vector>


extern "C" void dgetrf_(int* dim1, int* dim2, double* a, \
                         int* lda, int* ipiv, int* info);
extern "C" void dgetrs_(char *TRANS, int *N, int *NRHS, double *A, \
                        int *LDA, int *IPIV, double *B, int *LDB, int *INFO );

using namespace std;

#define N 3
#define NRHS 1

int main()
{
    char trans = 'N';
    int dim = N;
    int nrhs = NRHS;
    int LDA = N;
    int LDB = N;
    int info;
        
    double A[N*N] = {
        8.79,  9.93,  9.83,
        6.11,  6.91,  5.04,
       -9.15, -7.93,  4.86
    };
    
    double b[N*NRHS] = {
        1.0,
        1.0,
        1.0
    };
    

    int ipiv[N];

    //solve Ax = b
    dgetrf_(&dim, &dim, A, &LDA, ipiv, &info);
    std::cout << "Factorization complete" << std::endl;
    dgetrs_(&trans, &dim, &nrhs, A, &LDA, ipiv, b, &LDB, &info);
    std::cout << "Solution complete" << std::endl;

    //solution is in vector b
    std::cout << "Solution is:" << std::endl << "[";
    for (int i = 0; i < LDB-1; i++)
        std::cout << b[i] << ", "; 
    std::cout << b[LDB-1] << "]" << std::endl;

    return(0);
}
