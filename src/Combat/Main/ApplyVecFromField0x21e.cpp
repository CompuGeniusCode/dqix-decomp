#include <globaldefs.h>

void Clear0x28Bytes(void* p);
void ApplyVec3Tail(void* obj, int* vec);

// USA: func_020a2744
ARM void ApplyVecFromField0x21e(char* actor) {
    Clear0x28Bytes(actor + 0x248);
    *(int*)(actor + 0x220) = *(short*)(actor + 0x21e);
    ApplyVec3Tail(actor, (int*)(actor + 0x220));
}
