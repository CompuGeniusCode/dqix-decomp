#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Entry0202fdd0 {
    char pad0[0x30];
    short key;
    signed char val;
    char pad33[0x44 - 0x33];
};

struct List0202fdd0 {
    char pad0[0x124];
    int count;
    struct Entry0202fdd0 entries[1];
};


struct Obj021eb0f4 {
    char pad[0x582];
    unsigned char count;
    char pad2[1];
    unsigned short arr[1];
};

// USA: func_ov025_021eb0f4  (semantic: CheckAllKeysInList_021eb0f4)
extern "C" ARM int func_ov025_021eb0f4(struct Obj021eb0f4* obj) {
    struct List0202fdd0* list = (struct List0202fdd0*)(int)BackgroundLoader::GetInstance();
    unsigned short* p = obj->arr;
    for (int i = 0; i < obj->count; p++, i++) {
        if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(*p))) {
            return 0;
        }
    }
    return 1;
}
