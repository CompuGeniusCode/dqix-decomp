#include <globaldefs.h>

struct S02037484;
int MulFieldsDiv3102037484(struct S02037484* obj);

int GetField0xa2Short0207ebe8(void* obj);

struct Obj0207ebc4;
void ResetSubAndSetShort0207ebc4(struct Obj0207ebc4* obj, short val);

void DispatchByFlag42_020356f0(unsigned char* obj);

struct S02036000;
void WriteVec3ToReg02036000(struct S02036000* obj);

struct Obj02036024;
void ProcessOptionalPtrFields02036024(struct Obj02036024* obj);

struct S02036060;
void WriteVec3ShortToReg02036060(struct S02036060* obj);

extern "C" void func_02035554(void* obj, int arg);
extern "C" int func_0207e87c(void* obj, int arg);

struct S02035e74 {
    char pad0[0x8];
    void* field8;
    char pad0xc[0x6c - 0xc];
    unsigned int field6c;
};

// USA: func_02035e74
ARM int FinalizeCombatantUpdate02035e74(struct S02035e74* obj, int arg) {
    if (obj->field8 == NULL) {
        return 0;
    }
    unsigned char byteVal = (unsigned char)MulFieldsDiv3102037484((struct S02037484*)obj);
    if (byteVal == 0) {
        return 0;
    }
    if (obj->field6c & 1) {
        return 0;
    }
    if (obj->field6c & 0x800) {
        arg = 0;
    }
    func_02035554(obj, 0);
    if (byteVal != GetField0xa2Short0207ebe8(obj->field8)) {
        ResetSubAndSetShort0207ebc4((struct Obj0207ebc4*)obj->field8, byteVal);
    }
    DispatchByFlag42_020356f0((unsigned char*)obj);
    WriteVec3ToReg02036000((struct S02036000*)obj);
    ProcessOptionalPtrFields02036024((struct Obj02036024*)obj);
    WriteVec3ShortToReg02036060((struct S02036060*)obj);
    return func_0207e87c(obj->field8, arg);
}
