#include <globaldefs.h>
#include "std_library_functions.h"

struct InitSubstruct0205c73cData;
void InitSubstruct0205c73c(struct InitSubstruct0205c73cData* p);
struct Struct_0205c53c;
void ForwardInitChannelPair0205c564(struct Struct_0205c53c* s);
struct Foo02042fcc;
void ResetFoo02042fcc(struct Foo02042fcc* p);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_020462d0(void* base, void* dest, int size);

// USA: func_0205c840
ARM void InitBigStructVariant0205c840(char* obj) {
    unsigned char* base = (unsigned char*)GetGlobalField0x1c020421a0();
    base[0x19b0] = 0;

    InitSubstruct0205c73c((struct InitSubstruct0205c73cData*)(obj + 0x4));
    ForwardInitChannelPair0205c564((struct Struct_0205c53c*)(obj + 0x1c));
    ResetFoo02042fcc((struct Foo02042fcc*)(obj + 0xb4));

    *(int*)(obj + 0xd0) = 0;

    if (*(unsigned char*)(obj + 0x232) != 0) {
        unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
        for (int i = 0; i < *(unsigned char*)(obj + 0x232); i++) {
            unsigned short idx = *(unsigned short*)(obj + 0x220 + i * 2);
            func_020462d0(g, (unsigned short*)(obj + 0x120) + idx, 0x100);
        }
    }

    memset(obj + 0x120, 0, 0x100);
    memset(obj + 0x220, 0, 0x10);

    *(short*)(obj + 0x230) = 0;
    *(unsigned char*)(obj + 0x232) = 0;
    *(unsigned char*)(obj + 0x233) = 0;
    *(unsigned char*)(obj + 0x234) = 0;
}
