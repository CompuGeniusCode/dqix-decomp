#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int IsIndexMappedToSelf020a18f4(unsigned int idx);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_0203b080(void* obj);

extern char data_027e0000;

// USA: func_02012bd8
ARM void InitOverlay17ObjAndBumpBattleCounter02012bd8(void) {
    unsigned int idx;
    asm {
        ldr idx, =0x11
    }
    if (IsIndexMappedToSelf020a18f4(idx)) {
        func_ov017_0218b5b0();
        if (func_ov017_0218b5b0() != NULL) {
            func_0203b080(func_ov017_0218b5b0());
        }
    }
    int* p = (int*)((char*)GetBattleStruct() + 0x3c8);
    (*p)++;
    *(int*)((char*)&data_027e0000 + 0x3000 + 0xff8) |= 1;
}
