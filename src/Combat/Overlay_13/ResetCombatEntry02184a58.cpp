#include <globaldefs.h>

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;

void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_0205c96c(void*, int);
extern "C" void func_0205da88(void*, int, int, int);

extern "C" void func_ov013_02186cac(void*);
extern "C" void func_ov013_02186db4(void*);

// USA: func_ov013_02184a58
ARM void ResetCombatEntry02184a58(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char tag = o[0x63c];
    switch (tag) {
        case 0: case 5: case 6: return;
    }

    switch (tag) {
        case 3: case 4:
            func_0205c96c((void*)(o + 0x3d4), 0);
            break;
    }

    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(o + 0x38));
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)(o + 0x38));

    if (o[0x640]) {
        func_0205da88((void*)(o + 0x38), 0, 2, 0);
    } else {
        func_0205da88((void*)(o + 0x38), 1, 2, 1);
    }

    CallFunc0204b04cOverList0x98((Cont0205d274*)(o + 0x38));
    func_ov013_02186cac(obj);
    func_ov013_02186db4(obj);
}
