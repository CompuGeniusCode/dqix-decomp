#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Struct_0205d67c;
int GetFlagB4_0205d67c(struct Struct_0205d67c*);

// USA: func_ov023_021d8ddc  (semantic: InitFieldArrayFromLookup_021d8ddc)
extern "C" ARM void func_ov023_021d8ddc(void* obj, int* lut) {
    GetBattleStruct();
    unsigned char* idxArr = (unsigned char*)obj + 0x124;
    unsigned char count = *((unsigned char*)obj + 0x128);
    memset((char*)obj + 0xdc, 0, 0x10);
    for (int i = 0; i < count; i++) {
        *(int*)((char*)obj + 0xdc + i * 4) = lut[idxArr[i]];
    }
    int flag = GetFlagB4_0205d67c((struct Struct_0205d67c*)((char*)obj + 0x20));
    if (flag == 0) {
        *((unsigned char*)obj + 0x11c) = 0;
    } else {
        *((unsigned char*)obj + 0x11c) = 1;
    }
    *((unsigned char*)obj + 0x11a) = 1;
}
