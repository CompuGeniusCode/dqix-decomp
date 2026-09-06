#include <globaldefs.h>

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    void* field9C;
    char pad1[0x14];
    unsigned char fieldB4;
};

struct Struct_0205d81c* FindElementForFieldB0(struct Struct_0205d81c*);
int IsField0x9cEqual3(unsigned char* obj);
void SetFieldAt0x30(void* obj, int value);
extern "C" int func_0205d0e0(void*, int);

// USA: func_ov003_021694b8
ARM void UpdateEntryAndField4ea_021694b8(void* obj, int id) {
    struct Struct_0205d81c* entry = FindElementForFieldB0((struct Struct_0205d81c*)((char*)obj + 0xe4));
    if (entry != 0) {
        if (IsField0x9cEqual3((unsigned char*)entry)) {
            if (!(((unsigned char*)entry)[0xc5] & 0x2)) {
                SetFieldAt0x30((char*)obj + 0xe8, -1);
            }
        }
    }
    *((unsigned char*)obj + 0x4ea) = (unsigned char)func_0205d0e0((char*)obj + 0xe4, id);
}
