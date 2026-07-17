#include <globaldefs.h>

struct Struct02226f18_p { unsigned char pad[0x116]; unsigned char field116; };
struct Struct02226f18_base { unsigned char field0; unsigned char pad1[3]; Struct02226f18_p* field4; };
extern Struct02226f18_base data_ov031_02250c04;
extern void* data_ov031_02250c08;

extern "C" void func_ov031_0221e894(void*);
extern "C" void func_ov031_02236364(void*);
extern "C" void func_ov031_0223cf70(void*);

// USA: func_ov031_02226f18
ARM void AdvanceIfFlagged_02226f18(void* a) {
    func_ov031_0221e894(a);
    if (a != NULL) {
        Struct02226f18_p* p = data_ov031_02250c04.field4;
        if (p->field116 == 0 && data_ov031_02250c04.field0 == 1) {
            func_ov031_02236364((char*)p + 0x117);
        }
    }
    func_ov031_0223cf70(&data_ov031_02250c08);
}
