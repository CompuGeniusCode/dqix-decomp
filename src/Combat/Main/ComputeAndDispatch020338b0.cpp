#include <globaldefs.h>

extern "C" int func_02032424(int a, void* vec);
struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834*, int);

// USA: func_020338b0
ARM void ComputeAndDispatch020338b0(unsigned char* obj, int a) {
    int value = func_02032424(a, obj + 0x44);
    SetVecYByMode02033834((struct Obj02033834*)obj, value);
}
