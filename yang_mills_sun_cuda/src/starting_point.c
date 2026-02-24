#include "../../include/macro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef CUDA_MODE
#include <cuda_runtime.h>
#endif

#include "../../include/gauge_conf.h"
#include "../../include/geometry.h"
#include "../../include/gparam.h"
#include "../../include/random.h"

#include "../include/gpu_backend.h"


void real_main(char *in_file)
{
    Gauge_Conf GC;
    Geometry geo;
    GParam param;

    readinput(in_file, &param);
    initrand(param.d_randseed);

    init_indexing_lexeo();
    init_geometry(&geo, &param);
    init_gauge_conf(&GC, &geo, &param);

    // Move data to GPU / precompute neighbor tables.....
    gpu_backend_init(&GC, &geo, &param);

    // Thermalization + sampling (update only; no measures, no PT)
    for(long count = 0; count < param.d_sample; ++count)
    {
        gpu_backend_update(&GC, &geo, &param);
    }

    gpu_backend_finalize(&GC);
    free_gauge_conf(&GC, &param);
    free_geometry(&geo, &param);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((long)strlen(argv[1]) >= (long)STD_STRING_LENGTH)
    {
        fprintf(stderr, "Input file name too long (increase STD_STRING_LENGTH in include/macro.h)\n");
        return EXIT_FAILURE;
    }

    real_main(argv[1]);
    return EXIT_SUCCESS;
}