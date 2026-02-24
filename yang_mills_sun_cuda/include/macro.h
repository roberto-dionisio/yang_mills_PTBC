#ifndef MACRO_H
#define MACRO_H


// Check for CUDA errors
#define CUDA_CHECK(call) do { \
    cudaError_t err = call; \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA error in %s at line %d: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

// Define a macro for the maximum number of threads per block
#define MAX_THREADS_PER_BLOCK 1024

// Define a macro for the number of dimensions in the lattice
#define DIMENSIONS 4

// Define a macro for the SU(N) group ...
#define SU_N 3  

#endif // MACRO_H