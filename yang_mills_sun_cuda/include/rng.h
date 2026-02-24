#ifndef RNG_H
#define RNG_H

#include <curand_kernel.h>

__device__ void init_rng(curandState *state, unsigned long long seed) {
    curand_init(seed, 0, 0, state);
}

__device__ float random_float(curandState *state) {
    return curand_uniform(state);
}

__device__ int random_int(curandState *state, int min, int max) {
    return min + curand(state) % (max - min);
}

#endif // RNG_H