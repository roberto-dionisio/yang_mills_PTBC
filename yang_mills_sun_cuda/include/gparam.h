#ifndef GPARAM_H
#define GPARAM_H

typedef struct {
    long d_sample;       // Number of samples to generate
    unsigned long d_randseed; // Seed for random number generation
    int d_lattice_size;  // Size of the lattice
    int d_n;            // The SU(N) group parameter
    // Add other parameters as needed
} GParam;

void readinput(const char *filename, GParam *param);

#endif // GPARAM_H