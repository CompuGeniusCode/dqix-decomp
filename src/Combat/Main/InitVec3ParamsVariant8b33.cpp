#include <globaldefs.h>

void ApplyVec3Tail(void*, int*);
extern "C" void func_0202e9a4(void*, int);

// USA: func_020a2830
ARM void InitVec3ParamsVariant8b33(void* obj) {
    *(int*)((char*)obj + 0x224) = 0x8b33;
    *(int*)((char*)obj + 0x228) = 0xe666;
    ApplyVec3Tail(obj, (int*)((char*)obj + 0x220));
    func_0202e9a4(obj, 0x19000);
}
