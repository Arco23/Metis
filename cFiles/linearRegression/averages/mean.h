#ifndef MEAN_H
#define MEAN_H

#include <stddef.h>

#define STATS_MEAN_DEFINE(TYPE, RETTYPESYM, SUFFIX) \
RETTYPESYM mean_##SUFFIX(const TYPE * restrict x, size_t n);

STATS_MEAN_DEFINE(double, double, d)

#undef STATS_MEAN_DEFINE
#endif