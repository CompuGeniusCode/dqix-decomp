#include <globaldefs.h>

struct Rects02169674 {
    short originX;
    short originY;
    signed char count;
    char pad5;
    short* xMinArr;
    short* yMinArr;
    short* xWidthArr;
    short* yWidthArr;
};

// USA: func_ov003_02169674  (semantic: FindHitRectIndex_02169674)
extern "C" ARM int func_ov003_02169674(int unused, int x, int y, Rects02169674* s) {
    int relX = x - s->originX;
    int relY = y - s->originY;
    short* xMinArr = s->xMinArr;
    short* yMinArr = s->yMinArr;
    short* xWidthArr = s->xWidthArr;
    short* yWidthArr = s->yWidthArr;
    int count = s->count;
    for (int i = 0; i < count; i++) {
        int sumX = xMinArr[i] + xWidthArr[i];
        int sumY = yMinArr[i] + yWidthArr[i];
        if (relX < xMinArr[i]) continue;
        if (relX > sumX) continue;
        if (relY < yMinArr[i]) continue;
        if (relY <= sumY) return i;
    }
    return -1;
}
