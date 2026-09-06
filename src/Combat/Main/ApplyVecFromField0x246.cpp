#include <globaldefs.h>

void Clear0x28Bytes(void* p);
void ApplyVec3Tail(void* obj, int* vec);

// USA: func_020a2718
ARM void ApplyVecFromField0x246(char* actor) {
    Clear0x28Bytes(actor + 0x248);
    *(int*)(actor + 0x220) = *(short*)(actor + 0x246);
    ApplyVec3Tail(actor, (int*)(actor + 0x220));
}
