#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0205d2bc;
extern "C" void func_0204b088(struct Entry0205d2bc*, int);

extern "C" void func_ov023_021eb4f4(int);

extern "C" void func_ov008_02187278(void* obj, void* buf, int flag, int d);

struct StructA0205d5d0;
ARM int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

struct Obj021873ac;
ARM void ToggleBattleFlag_021873ac(struct Obj021873ac* obj, int flag);

struct Obj0205d2bc;
ARM void InitEntries0205d2bc(struct Obj0205d2bc* obj);

struct Obj02184968 {
    char pad00[0xb8];
    void* buf;
    char pad0[0xd0 - 0xbc];
    unsigned char fieldD0[0x8];
    char pad1[0xb08 - 0xd8];
    int f0xb08;
    char pad2[0xb10 - 0xb0c];
    signed char f0xb10;
    char pad3[0xb18 - 0xb11];
    int f0xb18;
    char pad4[0xb24 - 0xb1c];
    int f0xb24;
};

// USA: func_02184968
ARM void UpdateBattleField_02184968(void* objRaw) {
    struct Obj02184968* obj = (struct Obj02184968*)objRaw;
    if (obj->f0xb10 == 0 || obj->f0xb10 == 1 || obj->f0xb10 == 0xe) return;

    if (obj->f0xb24 == 0) {
        func_0204b088((struct Entry0205d2bc*)((char*)obj + 0xd0), 0);
    }

    if (obj->f0xb08 != 0) {
        func_ov023_021eb4f4(obj->f0xb08);
        return;
    }

    if (obj->f0xb18 & 0x800) {
        memset(obj->buf, 0, 0x960);
        func_ov008_02187278(obj, obj->buf, 0, 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->buf, 1, 0);
        obj->f0xb18 &= ~0x800;
    }
    ToggleBattleFlag_021873ac((struct Obj021873ac*)obj, 1);
    InitEntries0205d2bc((struct Obj0205d2bc*)((char*)obj + 0x130));
}
