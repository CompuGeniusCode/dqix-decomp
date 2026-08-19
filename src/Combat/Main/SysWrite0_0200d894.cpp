#include <globaldefs.h>

struct MirroredPointStruct_020c129c {
    int x0;
    int y0;
    int zero0;
    int negY;
    int x1;
    int zero1;
    int zero2;
    int zero3;
    int one;
};

// USA: func_020c129c
extern "C" THUMB void InitMirroredPointStruct_020c129c(MirroredPointStruct_020c129c* out, int y, int x) {
    out->x0 = x;
    out->y0 = y;
    out->zero0 = 0;
    out->negY = -y;
    out->x1 = x;
    out->zero1 = 0;
    out->zero2 = 0;
    out->zero3 = 0;
    out->one = 0x1000;
}
