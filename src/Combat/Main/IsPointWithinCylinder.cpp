#include <globaldefs.h>

struct Point02032148 {
    int x;
    int y;
    int z;
};

struct Cylinder02032148 {
    int x;
    int y;
    int z;
    int radius;
    int height;
};

static inline int FixedMul02032148(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_02032148
ARM int IsPointWithinCylinder(struct Point02032148* p, struct Cylinder02032148* c) {
    int dx;
    int dz;
    int dz2;
    int dx2;
    int sum;
    if (c->y > p->y) return 0;
    if (c->y + c->height < p->y) return 0;
    dx = p->x - c->x;
    dz = p->z - c->z;
    dz2 = FixedMul02032148(dz, dz);
    dx2 = FixedMul02032148(dx, dx);
    sum = dx2 + dz2;
    if (FixedMul02032148(c->radius, c->radius) >= sum) return 1;
    return 0;
}
