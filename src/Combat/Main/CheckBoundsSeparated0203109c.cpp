#include <globaldefs.h>

struct Bounds0203109c {
    int minx;
    int miny;
    int minz;
    int maxx;
    int maxy;
    int maxz;
};

// USA: func_0203109c
ARM int CheckBoundsSeparated0203109c(struct Bounds0203109c* a, struct Bounds0203109c* b) {
    if (a->minx < b->maxx) return 0;
    if (a->miny < b->maxy) return 0;
    if (a->minz < b->maxz) return 0;
    if (b->minx < a->maxx) return 0;
    if (b->miny < a->maxy) return 0;
    if (b->minz < a->maxz) return 0;
    return 1;
}
