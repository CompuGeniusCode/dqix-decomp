#include <globaldefs.h>
#include "std_library_functions.h"

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
extern "C" void func_ov008_02187278(void* obj, char* dst, int mode, void* extra);

struct Obj021873ac {
    char pad[0xb8];
    char* bufPtr;
    char pad2[0xb18 - 0xbc];
    int flags;
};

// USA: func_ov008_021873ac
ARM void UpdateElementBuffer_021873ac(struct Obj021873ac* obj, int modeArg) {
    if (modeArg == 0) {
        if (!(obj->flags & 0x800)) return;
        memset(obj->bufPtr, 0, 0x960);
        func_ov008_02187278(obj, obj->bufPtr, modeArg, 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1, 0);
        obj->flags &= ~0x800;
    } else if (modeArg == 1) {
        if (!(obj->flags & 0x1000)) return;
        memset(obj->bufPtr, 0, 0x960);
        func_ov008_02187278(obj, obj->bufPtr, modeArg, 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 2, (int)obj->bufPtr, 1, 0);
        obj->flags &= ~0x1000;
    }
}
