#include "gpu_backend.h"

#ifdef CUDA_MODE
#include <cuda_runtime.h>
#include <cstdio>
#endif

extern "C" {

void gpu_backend_init(Gauge_Conf *GC, Geometry const *geo, GParam const *param)
{
    (void)GC; (void)geo; (void)param;
#ifdef CUDA_MODE
    int dev = -1;
    cudaGetDevice(&dev);

    cudaDeviceProp prop{};
    cudaGetDeviceProperties(&prop, dev);

    std::fprintf(stderr, "[gpu_backend] init on device %d: %s\n", dev, prop.name);
    
    cudaDeviceSynchronize();
#endif
}

void gpu_backend_update(Gauge_Conf *GC, Geometry const *geo, GParam const *param)
{
    (void)GC; (void)geo; (void)param;
#ifdef CUDA_MODE
    // No-op for now 
    cudaDeviceSynchronize();
#endif
}

void gpu_backend_finalize(Gauge_Conf *GC)
{
    (void)GC;
#ifdef CUDA_MODE
    cudaDeviceSynchronize();
#endif
}

}