#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_0203f2b0(void* entry);

// USA: func_0203dd94
ARM void NotifyAllEntries0203dd94(char* obj) {
    int i;
    if (*(int*)(obj + 0x98) & 1) return;
    GetBattleStruct();
    for (i = 0; i < 0x20; i++) {
        char* entry = *(char**)(obj + i * 4 + 0xc);
        if (entry != NULL && *(void**)(entry + 0x14) != NULL) {
            func_0203f2b0(*(void**)(entry + 0x14));
        }
    }
}
