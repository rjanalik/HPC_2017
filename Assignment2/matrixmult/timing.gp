set title "NxN matrix-matrix-multiplication on 10-Core Intel(R) Xeon(R) CPU E5-2650 v3 @ 2.30GHz"
set xlabel "Matrix size (N)"
set ylabel "Performance (MFlop/s)"
set grid

set terminal postscript color "Helvetica" 14
set output "timing.ps"

# set terminal png color "Helvetica" 14
# set output "timing.png"

# plot "timing.data" using 2:4 title "square_dgemm" with linespoints


# For performance comparisons

plot "timing_basic_dgemm.data"   using 1:2 title "Naive dgemm" with linespoints, \
     "timing_blocked_dgemm.data" using 1:2 title "Student dgemm" with linespoints, \
     "timing_blas_dgemm.data"   using 1:2 title "OpenBLAS dgemm" with linespoints
