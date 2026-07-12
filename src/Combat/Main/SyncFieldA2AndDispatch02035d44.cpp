#include <globaldefs.h>

struct Ctx020359c8;
int CheckAndToggleFlag0x200000(struct Ctx020359c8* obj);

extern "C" void func_02035554(void* obj, int arg);

struct S02037484;
int MulFieldsDiv3102037484(struct S02037484* obj);

int GetField0xa2Short0207ebe8(void* obj);

struct Obj0207ebc4;
void ResetSubAndSetShort0207ebc4(struct Obj0207ebc4* obj, short val);

void DispatchByFlag42_020356f0(unsigned char* obj);

extern "C" int func_0207e87c(void* obj, int arg);

struct S02035d44 {
    char pad0[0x8];
    void* field8;
    char pad0xc[0x6c - 0xc];
    unsigned int field6c;
};

// USA: func_02035d44
ARM int SyncFieldA2AndDispatch02035d44(struct S02035d44* obj, int arg) {
    if (!CheckAndToggleFlag0x200000((struct Ctx020359c8*)obj)) {
        return 0;
    }
    if (obj->field6c & 0x800) {
        arg = 0;
    }
    func_02035554(obj, 0);
    unsigned char byteVal = (unsigned char)MulFieldsDiv3102037484((struct S02037484*)obj);
    if (byteVal != GetField0xa2Short0207ebe8(obj->field8)) {
        ResetSubAndSetShort0207ebc4((struct Obj0207ebc4*)obj->field8, byteVal);
    }
    DispatchByFlag42_020356f0((unsigned char*)obj);
    return func_0207e87c(obj->field8, arg);
}
