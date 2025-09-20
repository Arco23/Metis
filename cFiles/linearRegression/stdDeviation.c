#include <stdio.h>
#include <math.h>
#include <stddef.h>

#define STATS_STDDEV_DEFINE(TYPE, RETTYPESYM, SUFFIX)\
static inline RETTYPESYM stdDeviation_##SUFFIX##_pop(const TYPE * restrict x, size_t n){\
\
    if(n == 0){\
        return NAN ;\
    }\
    double xSum = 0;\
    double xsubMeanSum = 0;\
\
    for(size_t i = 0; i < n; i++)xSum += x[i];\
\
    double mean = xSum/n;\
\
    for(size_t i = 0; i < n; i++){\
        xsubMeanSum += (x[i]-mean)*(x[i]-mean);\
    }\
\
    return (RETTYPESYM)sqrt(xsubMeanSum/n);\
}\
static inline RETTYPESYM stdDeviation_##SUFFIX##_sample(const TYPE * restrict x, size_t n){\
\
    if(n == 0){\
        return NAN;\
    }\
\
    double xSum = 0;\
    double xsubMeanSum = 0;\
\
    for(size_t i = 0; i < n; i++){\
        xSum += x[i];\
    }\
\
    double mean = xSum/n;\
\
    for(size_t i = 0; i < n; i++){\
        xsubMeanSum += (x[i]-mean)*(x[i]-mean);\
    }\
\
    return (RETTYPESYM)sqrt(xsubMeanSum/(n-1));\
}

STATS_STDDEV_DEFINE(double, double, d)
STATS_STDDEV_DEFINE(float,  float,  f) 
STATS_STDDEV_DEFINE(int,    double, i)


#undef STATS_STDDEV_DEFINE

int main(){

    return 0;
}

