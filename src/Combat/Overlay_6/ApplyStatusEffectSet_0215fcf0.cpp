#include <globaldefs.h>

struct StatusOwner02081164;
struct Obj2081;

extern void SetEntryHalfword0xe(void* obj, int id, int value);
extern void SetSublistEntryField14LowBits_02080798(void* obj, int id, int value);
extern void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* owner, int id, int enable);
extern "C" int func_020813ec(void* obj, int id);
extern void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
extern void ClearElementFlag0x20(struct Obj2081* obj, int key);

struct Obj0215fcf0 {
    char pad0[0x14];
    void* f14;
    char pad1[0x386 - 0x18];
    unsigned char f386;
};

// USA: func_ov006_0215fcf0  (semantic: ApplyStatusEffectSet_0215fcf0)
extern "C" ARM void func_ov006_0215fcf0(struct Obj0215fcf0* obj) {
    void* sub = obj->f14;
    int val = (short)(obj->f386 + 0x29);
    SetEntryHalfword0xe(sub, 0x5a, val);
    SetSublistEntryField14LowBits_02080798(sub, 0x5a, 1);
    SetEntryFlag0x2ByShortId((struct StatusOwner02081164*)sub, 0xf, 1);
    func_020813ec(sub, 0xf);
    SetEntryLowNibbleAndElement02080c68(sub, 0xf, 2);
    ClearElementFlag0x20((struct Obj2081*)sub, 0xf);
}
