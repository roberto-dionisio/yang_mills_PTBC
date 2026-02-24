#ifndef GAUGE_CONF_H
#define GAUGE_CONF_H

#include "suN.h"
#include "gparam.h"

typedef struct {
    int L;          // Lattice size
    int N;          // Number of colors (SU(N))
    float *links;   // Pointer to the gauge links (matrix representation)
} Gauge_Conf;

// Function declarations
void init_gauge_conf(Gauge_Conf *GC, const GParam *param);
void free_gauge_conf(Gauge_Conf *GC, const GParam *param);
void generate_gauge_configurations(Gauge_Conf *GC, const GParam *param);

#endif // GAUGE_CONF_H