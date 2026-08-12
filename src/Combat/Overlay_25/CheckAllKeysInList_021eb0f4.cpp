#include <globaldefs.h>

int GetData02104304Field4(void);

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

extern "C" int func_0202fdd0(struct List0202fdd0* obj, int key);

struct Obj021eb0f4 {
    char pad[0x582];
    unsigned char count;
    char pad2[1];
    unsigned short arr[1];
};

// USA: func_ov025_021eb0f4  (semantic: CheckAllKeysInList_021eb0f4)
extern "C" ARM int func_ov025_021eb0f4(struct Obj021eb0f4* obj) {
    struct List0202fdd0* list = (struct List0202fdd0*)GetData02104304Field4();
    unsigned short* p = obj->arr;
    for (int i = 0; i < obj->count; p++, i++) {
        if (!func_0202fdd0(list, *p)) {
            return 0;
        }
    }
    return 1;
}
