#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0202c410
ARM void CopyBattleTailToObjField0x102c(void* obj) {
    *((unsigned char*)obj + 0x1029) |= 0x48;
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned char buf[6];
    unsigned char* dst = buf;
    unsigned char* src = (unsigned char*)battleStruct + 0x74fe;
    int n = 6;
    do {
        unsigned char* d = dst++;
        unsigned char t = *src++;
        *d = t;
    } while (--n);
    dst = (unsigned char*)obj + 0x102c;
    src = buf;
    n = 6;
    do {
        unsigned char* d = dst++;
        unsigned char t = *src++;
        *d = t;
    } while (--n);
}
