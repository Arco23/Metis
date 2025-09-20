#include <math.h>
#include <stdio.h>
#include <stddef.h>

#define STATS_DOT_DEFINE(TYPE, RETTYPESYM, SUFFIX)\
static inline RETTYPESYM dot_##SUFFIX(const TYPE * restrict x,const TYPE * restrict y, size_t n) {\
    \
    if(n==0){\
        return NAN;\
    }\
\
    double result = 0.0;\
\
    for(size_t i = 0; i<n;i++){\
        result += x[i]*y[i];\
    }\
\
    return (RETTYPESYM)result;\
}

STATS_DOT_DEFINE(double,double,d)
STATS_DOT_DEFINE(float,float,f)
STATS_DOT_DEFINE(int,int,i)

#undef STATS_DOT_DEFINE

int main() {

    return 0;

}