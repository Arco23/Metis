#include <math.h>
#include <stdio.h>
#include <stddef.h>

#define STATS_MEAN_DEFINE(TYPE, RETTYPESYM, SUFFIX)\
static inline RETTYPESYM mean_##SUFFIX(const TYPE * restrict x, size_t n){\
    \
    if(n==0){\
        return NAN;\
    }\
    \
    double xSum = 0;\
\
    for(size_t i = 0;i<n; i++) xSum += x[i];\
    \
    return (RETTYPESYM)(xSum/n);\
}

STATS_MEAN_DEFINE(double, double, d)
STATS_MEAN_DEFINE(float, float, f)
STATS_MEAN_DEFINE(int, double, i )

#undef STATS_MEAN_DEFINE


int main(){

    return 0;
}