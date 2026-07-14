#include <globaldefs.h>

struct Entity02035c40 {
    char pad0[0x8];
    void* f8;
    char pad1[0x41 - 0xc];
    unsigned char f41;
    char pad2[0x44 - 0x42];
    int f44[3];
    char pad3[0x68 - 0x50];
    int f68;
    unsigned int f6c;
    char pad4[0x84 - 0x70];
    int f84[3];
};

struct Ctx020359c8;
extern int CheckAndToggleFlag0x200000(struct Ctx020359c8*);

struct S02037484;
extern int MulFieldsDiv3102037484(struct S02037484*);

extern int GetField0xa2Short0207ebe8(void*);

struct Obj0207ebc4;
extern void ResetSubAndSetShort0207ebc4(struct Obj0207ebc4*, short);

extern void DispatchByFlag42_020356f0(unsigned char*);

extern void InvokeHandlerAndClearFlags020b3814(void);

struct FlagStruct;
extern int CheckField98SetAndField94Clear(struct FlagStruct*);

void CopyVec3(int* dst, int* src);

extern "C" void func_02035554(void*, int);
extern "C" int func_0207e87c(void*, int);
extern "C" void func_02037674(void*);
extern "C" void func_02037934(void*, void*);

// USA: func_02035c40
ARM int UpdateEntityFieldsAndDispatch02035c40(struct Entity02035c40* obj, int val) {
    short r4;
    int result;
    obj->f41 &= ~0x20;
    if (!CheckAndToggleFlag0x200000((struct Ctx020359c8*)obj)) {
        return 0;
    }
    if (obj->f6c & 0x800) {
        val = 0;
    }
    func_02035554(obj, 0);
    r4 = MulFieldsDiv3102037484((struct S02037484*)obj) & 0xff;
    if (r4 != GetField0xa2Short0207ebe8(obj->f8)) {
        ResetSubAndSetShort0207ebc4((struct Obj0207ebc4*)obj->f8, r4);
    }
    DispatchByFlag42_020356f0((unsigned char*)obj);
    InvokeHandlerAndClearFlags020b3814();
    result = func_0207e87c(obj->f8, val);
    obj->f41 = (obj->f41 & ~0x20) | ((unsigned)(unsigned char)result << 0x1f >> 0x1a);
    if (result != 0) {
        if (obj->f6c & 4) {
            func_02037674(obj);
        }
        if (CheckField98SetAndField94Clear((struct FlagStruct*)obj)) {
            func_02037934(obj, obj);
        }
    } else {
        if (obj->f6c & 4) {
            CopyVec3(obj->f84, obj->f44);
            obj->f84[1] = obj->f44[1] + obj->f68 / 2;
        }
    }
    return result;
}
