#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_0203f370(void* obj);

struct Entry0203dde0 {
    char pad[0x14];
    void* field14;
};

struct Obj0203dde0 {
    char pad0[0xc];
    struct Entry0203dde0* entries[0x20];
    char pad2[0xc];
    unsigned int field98;
};

// USA: func_0203dde0
ARM void UpdateEntrySubObjects0203dde0(struct Obj0203dde0* obj) {
    int i;
    if (obj->field98 & 0x1) {
        return;
    }
    GetBattleStruct();
    for (i = 0; i < 0x20; i++) {
        struct Entry0203dde0* entry = obj->entries[i];
        if (entry != NULL && entry->field14 != NULL) {
            func_0203f370(entry->field14);
        }
    }
}
