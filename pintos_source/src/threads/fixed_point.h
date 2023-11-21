#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

typedef int fixed_point;

#define FRACTION 15
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


#define CONVERT_TO_FIXED_POINT(x) ((fixed_point)(x << FRACTION))
#define CONVERT_TO_INT_TOWARD_ZERO(x) (x >> FRACTION)
#define CONVERT_TO_INT_NEAREST(x) (x >= 0 ? ((x + (1 << (FRACTION - 1))) >> FRACTION) : ((x - (1 << (FRACTION - 1))) >> FRACTION))
#define ADD_FIXED_POINT(x,y) (x + y)
#define ADD_INTEGER(x,n) (x + (n << FRACTION))
#define SUB_FIXED_POINT(x,y) (x - y)
#define SUB_INTEGER(x,n) (x - (n << FRACTION))
#define MULTIPLY_FIXED_POINT(x,y) (x * y)
#define MULTIPLY_INTEGER(x,n) ((fixed_point)(((int64_t) x) * n >> FRACTION))
#define DIVIDE_FIXED_POINT(x,y) (x / y)
#define DIVIDE_INTEGER(x,n) ((fixed_point)((((int64_t) x) << FRACTION) / n))

#endif /* thread/fixed_point.h */
