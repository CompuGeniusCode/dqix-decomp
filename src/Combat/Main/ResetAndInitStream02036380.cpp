#include <globaldefs.h>

struct StreamState020345e0;
void InitStreamState020345e0(struct StreamState020345e0* self);

// USA: func_02036380
ARM void ResetAndInitStream02036380(unsigned char* obj) {
    *(int*)obj = *(int*)obj & ~1 & 0xfffffe01;
    *(int*)(obj + 0x28) = 0;
    *(int*)(obj + 0x24) = 0;
    InitStreamState020345e0((struct StreamState020345e0*)(obj + 4));
}
