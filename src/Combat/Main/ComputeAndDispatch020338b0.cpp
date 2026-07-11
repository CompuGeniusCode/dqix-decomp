#include <globaldefs.h>
int AimAwayFromTargetFlat(struct Vec3*, struct Vec3*);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834*, int);

// USA: func_020338b0
ARM void ComputeAndDispatch020338b0(unsigned char* obj, int a) {
    int value = AimAwayFromTargetFlat((struct Vec3*)(a), (struct Vec3*)(obj + 0x44));
    SetVecYByMode02033834((struct Obj02033834*)obj, value);
}
