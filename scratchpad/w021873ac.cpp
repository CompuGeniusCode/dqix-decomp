#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov008_02187278(void* obj, void* buf, int flag, int d);

struct StructA0205d5d0;
ARM int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

struct Obj021873ac {
    char pad0[0xb8];
    void* buf;
    char pad1[0xb18 - 0xbc];
    int f0xb18;
};

// USA: func_021873ac
ARM void ToggleBattleFlag_021873ac(struct Obj021873ac* obj, int flag) {
    if (flag == 0) {
        if (!(obj->f0xb18 & 0x800)) return;
        memset(obj->buf, 0, 0x960);
        func_ov008_02187278(obj, obj->buf, flag, 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->buf, 1, 0);
        obj->f0xb18 &= ~0x800;
    } else {
        if (flag != 1) return;
        if (!(obj->f0xb18 & 0x1000)) return;
        memset(obj->buf, 0, 0x960);
        func_ov008_02187278(obj, obj->buf, flag, 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 2, (int)obj->buf, 1, 0);
        obj->f0xb18 &= ~0x1000;
    }
}
