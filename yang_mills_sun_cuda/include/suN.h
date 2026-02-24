#ifndef SUN_H
#define SUN_H

#include <cuda_runtime.h>

typedef struct {
    int N; // Dimension of the gauge group SU(N)
    int lattice_size; // Total number of sites in the lattice
    float *gauge_fields; // Pointer to the gauge fields on the GPU
} SU_N_Config;

// Function to initialize SU(N) gauge configurations
void init_SU_N_config(SU_N_Config *config, int N, int lattice_size);

// Function to generate random gauge configurations for SU(N)
__global__ void generate_random_gauge(SU_N_Config *config);

// Function to normalize gauge fields
__device__ void normalize_gauge(float *gauge_field);

// Function to free memory allocated for SU(N) configurations
void free_SU_N_config(SU_N_Config *config);

#endif // SUN_H