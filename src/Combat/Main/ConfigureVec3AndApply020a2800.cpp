#include <globaldefs.h>
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4*, int);

void ApplyVec3Tail(void*, int*);

struct Struct020A2800 {
    char pad[0x220];
    int vecX;   // 0x220
    int vecY;   // 0x224
    int vecZ;   // 0x228
};

// USA: func_020a2800
ARM void ConfigureVec3AndApply020a2800(struct Struct020A2800* obj) {
    obj->vecY = 0x6000;
    obj->vecZ = 0xb000;
    ApplyVec3Tail(obj, &obj->vecX);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)(obj), (int)(0xf000));
}
