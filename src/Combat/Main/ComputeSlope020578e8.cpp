#include <globaldefs.h>

struct Point020578e8 {
    int x;
    float y;
};
struct Wrap020578e8 {
    Point020578e8* p;
};

// USA: func_020578e8
ARM float ComputeSlope020578e8(Wrap020578e8* a, Wrap020578e8* b) {
    Point020578e8* pa = a->p;
    Point020578e8* pb = b->p;
    return (pb->y - pa->y) / (float)(pb->x - pa->x);
}
