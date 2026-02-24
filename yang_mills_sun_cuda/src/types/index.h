#ifndef INDEX_H
#define INDEX_H

#include <cuda_runtime.h>

//gauge configurations
typedef struct {
    int N; // Dimension of the gauge group SU(N)
    int lattice_size; // Total number of sites in the lattice
    float *gauge_fields; // Pointer to the gauge fields data on the GPU
} GaugeConfig;

// geometry
typedef struct {
    int dimensions; // Number of dimensions of the lattice
    int *lattice_shape; // Array to hold the shape of the lattice
} Geometry;

//proto for managing gauge configurations and geometry
void initialize_gauge_config(GaugeConfig *gc, int N, int lattice_size);
void free_gauge_config(GaugeConfig *gc);
void initialize_geometry(Geometry *geo, int dimensions, int *shape);
void free_geometry(Geometry *geo);

#endif 