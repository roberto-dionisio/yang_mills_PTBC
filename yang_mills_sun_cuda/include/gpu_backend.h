#ifndef GPU_BACKEND_H
#define GPU_BACKEND_H

//#include "../../include/gauge_conf.h"
//#include "../../include/geometry.h"
//#include "../../include/gparam.h"
// just to test the linking, fwd decl
typedef struct Gauge_Conf Gauge_Conf;
typedef struct Geometry Geometry;
typedef struct GParam GParam;

#ifdef __cplusplus
extern "C" {
#endif
// Function to initialize the GPU resources for gauge configuration generation
void gpu_backend_init(Gauge_Conf *GC, Geometry const *geo, GParam const *param);

// Function to update gauge configurations on the GPU
void gpu_backend_update(Gauge_Conf *GC, Geometry const *geo, GParam const *param);

// Function to finalize GPU resources and clean up
void gpu_backend_finalize(Gauge_Conf *GC);
#ifdef __cplusplus
}
#endif

#endif // GPU_BACKEND_H