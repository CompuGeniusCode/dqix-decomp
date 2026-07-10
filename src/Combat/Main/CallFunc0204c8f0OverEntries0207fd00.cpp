#include <globaldefs.h>

extern "C" void func_0204c8f0(void* entry);

struct Obj0207fd00 {
    char pad0[0x2c];
    void* field_2c;
    char* entries;
    char pad34[5];
    unsigned char count;
};

// USA: func_0207fd00
ARM void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj) {
    unsigned char count;
    char* e;
    unsigned char i;
    if (obj->field_2c != NULL && obj->entries != NULL) {
        e = obj->entries;
        count = obj->count;
        for (i = 0; i < count; i++) {
            func_0204c8f0(e);
            e += 0xe0;
        }
    }
}
