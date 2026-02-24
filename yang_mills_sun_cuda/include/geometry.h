#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    int dimensions; // Number of dimensions of the lattice
    int *sizes;     // Array holding the size of the lattice in each dimension
} Geometry;

// Function to initialize the geometry structure
void init_geometry(Geometry *geo, const GParam *param);

// Function to free the geometry structure
void free_geometry(Geometry *geo, const GParam *param);

// Function to compute neighbor indices in the lattice
void compute_neighbors(Geometry *geo);

#endif // GEOMETRY_H