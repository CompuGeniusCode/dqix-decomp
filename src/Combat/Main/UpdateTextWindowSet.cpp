#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xc4];
    unsigned char fieldC4;
    char pad1[0xd8 - 0xc5];
    unsigned char fieldD8_bit0 : 1;
    unsigned char fieldD8_rest : 7;
    unsigned char fieldD9;
    unsigned char fieldDA;
    char pad2[0xe0 - 0xdb];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* field9C;
    char pad1[0xb0 - 0xa0];
    unsigned char fieldB0;
    char pad2[0xb3 - 0xb1];
    unsigned char fieldB3;
    char pad3[0xb8 - 0xb4];
    unsigned char fieldB8;
};

struct Struct0205d888;
extern "C" void* func_0205d888(struct Struct0205d888* p);

extern "C" int func_0205c5b0(void* selfPtr, int p1);
extern "C" unsigned int func_0205c710(unsigned char* obj);
extern "C" void func_0205042c(unsigned char* obj, unsigned char value);
extern "C" unsigned int func_0205c6e4(unsigned char* obj);
extern "C" void func_02050440(unsigned char* obj, int val);
extern "C" void func_0204c87c(void* entry, int arg);
extern "C" struct Elem_0205d81c* FindTextWindowById(struct Struct_0205d81c* s, int key);
struct Obj0204ffc0;
extern "C" void func_0204ffc0(struct Obj0204ffc0* a, int b);

// One frame of the whole window set. func_0205c5b0 runs the two cursors and returns 0, 1 or 2, and
// when the topmost window (func_0205d888) is the focused one and has its +0xd8 bit set, the active
// cursor's +0x14 and +0x4 are pushed into its +0xd9 and +0xda -- +0x14 is the page index that
// GetGridCursorEntryIndex multiplies by, not a row; the row and column live at +0x18 and +0x1c.
// Every slot below +0xb3 then gets func_0204c87c, and last the id parked at +0xb8 -- 0xff meaning
// none -- is looked up and run through func_0204ffc0, then reset so the re-upload happens once.
extern "C" ARM int UpdateTextWindowSet(void* objPtr, int val) {
    struct Struct_0205d81c* obj = (struct Struct_0205d81c*)objPtr;
    int ret;
    struct Elem_0205d81c* entry;
    unsigned char i;

    if (obj->field98 == 0) return 0;
    if (obj->field9C == 0) return 0;

    ret = 0;
    entry = (struct Elem_0205d81c*)func_0205d888((struct Struct0205d888*)objPtr);
    if (entry != 0) {
        ret = func_0205c5b0(objPtr, val);
        if (obj->fieldB0 == entry->fieldC4) {
            if (entry->fieldD8_bit0) {
                func_0205042c((unsigned char*)entry, func_0205c710((unsigned char*)objPtr));
                func_02050440((unsigned char*)entry, (unsigned char)func_0205c6e4((unsigned char*)objPtr));
            }
        }
    }

    for (i = 0; i < obj->fieldB3; i++) {
        func_0204c87c((void*)&obj->field9C[i], val);
    }

    if (obj->fieldB8 != 0xff) {
        entry = FindTextWindowById(obj, obj->fieldB8);
        if (entry != 0) {
            func_0204ffc0((struct Obj0204ffc0*)entry, -1);
        }
        obj->fieldB8 = 0xff;
    }

    return ret;
}
