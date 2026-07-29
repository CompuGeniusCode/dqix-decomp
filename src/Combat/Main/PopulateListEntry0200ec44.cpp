#include <globaldefs.h>

struct Obj0200ec44 {
    unsigned char* namePtr;   // +0x0
    int field4;                 // +0x4
    int field8;                  // +0x8
    char pad[0x18 - 0xc];
    char* list;                    // +0x18
};

struct Entry0200ec44 {
    int field0;    // +0x0
    int field4;     // +0x4
    int field8;      // +0x8
    int field0xc;     // +0xc
    int field0x10;      // +0x10
};

// USA: func_0200ec44  (semantic: PopulateListEntry0200ec44)
extern "C" ARM void func_0200ec44(struct Obj0200ec44* obj, int offset, int extra) {
    struct Entry0200ec44* entry = (struct Entry0200ec44*)(obj->list + offset);
    entry->field0 = obj->field4;
    entry->field4 = (int)obj->namePtr;
    entry->field8 = obj->field8;
    if (*obj->namePtr != '*') {
        entry->field0xc = obj->field4 + extra;
        return;
    }
    entry->field0xc = (int)&entry->field0x10;
    entry->field0x10 = *(int*)obj->field4 + extra;
}
