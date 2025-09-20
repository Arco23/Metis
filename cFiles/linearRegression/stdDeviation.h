#ifndef STDDEVIATION_H
#define STDDEVIATION_H

#include <stddef.h>

#define STATS_STDDEV_DEFINE(TYPE, RETTYPESYM, SUFFIX) \
RETTYPESYM stdDeviation_##SUFFIX##_pop(const TYPE * restrict x, size_t n); \
RETTYPESYM stdDeviation_##SUFFIX##_sample(const TYPE * restrict x, size_t n);

STATS_STDDEV_DEFINE(double, double, d)
STATS_STDDEV_DEFINE(float,  float,  f)
STATS_STDDEV_DEFINE(int,    double, i)
#undef STATS_STDDEV_DEFINE 
#endif