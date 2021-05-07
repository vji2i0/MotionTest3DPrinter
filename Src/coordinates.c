#include "coordinates.h"

static long x, y, z, e, z1, z2;


void create_coordinates(void) { x=0; y=0; z=0; e=0; z1=0; z2=0; }

long getX_coordinates(void) { return x; }
long getY_coordinates(void) { return y; }
long getZ_coordinates(void) { return z; }
long getE_coordinates(void) { return e; }

void incX_coordinates(void) { x++; }
void incY_coordinates(void) { y++; }
void incZ_coordinates(void) { z++; }
void incE_coordinates(void) { e++; }

void decX_coordinates(void) { x--; }
void decY_coordinates(void) { y--; }
void decZ_coordinates(void) { z--; }
void decE_coordinates(void) { e--; }

long getZ1_coordinates(void) { return z1; }
void incZ1_coordinates(void) { z1++; }
void decZ1_coordinates(void) { z1--; }
long getZ2_coordinates(void) { return z2; }
void incZ2_coordinates(void) { z2++; }
void decZ2_coordinates(void) { z2--; }
