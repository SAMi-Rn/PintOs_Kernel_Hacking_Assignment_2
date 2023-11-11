#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define FRACTION (1 << 14)


// Convert x to integer (rounding toward zero):	x / f
// convert x to integer rounding to nearest!
// (x + f / 2) / f if x >= 0,
// (x - f / 2) / f if x <= 0.
// Add x and y:	x + y
// Subtract y from x:	x - y
// Add x and n:	x + n * f
// Subtract n from x:	x - n * f
// Multiply x by y:	((int64_t) x) * y / f
// Multiply x by n:	x * n
// Divide x by y:	((int64_t) x) * f / y
// Divide x by n:	x / n

#define CONVERT_TO_FIXED_POINT(x) (x) * (FRACTION)
#define CONVERT_TO_INT_TOWARD_ZERO(x) (x) * (FRACTION)
#define CONVER_TO_INT_NEAREST(x) ((x) >= 0 ? ((x) + (FRACTION) / 2) / (FRACTION) : ((x) - (FRACTION) /2) / (FRACTION))
#define ADD_FIXED_POINT(x, y) (x) + (y) 
#define ADD_INTEGER(x, n) (x) + (n) * (FRACTION)
#define MULTIPLY_FIXED_POINT(x, y) ((int64_t) (x)) * (y) / (FRACTION)
#define MULTIPLY_INTEGER(x, n) (x) * (n)
#define DIVIDE_FIXED_POINT(x, y) ((int64_t) x) * (FRACTION / (y))
#define DIVIDE_INTEGER(x, n) (x) / (n)



#endif //threads/fixed_point.h
