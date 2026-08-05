#include <globaldefs.h>

extern "C" int func_0207e97c(void* obj);
struct FlagDispatchContext020B426C;
void UpdateFlagBitsAndDispatch(struct FlagDispatchContext020B426C* obj);

struct Obj0207e87c {
    unsigned int flags;  // 0x0
    char pad[0xa4];      // 0x4..0xa7
    signed int bit0 : 1; // 0xa8 bit0 (0x1)
    signed int bit1 : 1; // 0xa8 bit1 (0x2)
    signed int bit2 : 1; // 0xa8 bit2 (0x4)
};

// USA: func_0207e87c  (semantic: DispatchIfFlagsSet_0207e87c)
extern "C" ARM int func_0207e87c(struct Obj0207e87c* obj, int prep) {
    if (!obj->bit0) {
        return 0;
    }
    if (prep != 0) {
        if (func_0207e97c(obj) == 0) {
            return 0;
        }
    }
    if (obj->bit2) {
        obj->flags |= 1;
        UpdateFlagBitsAndDispatch((struct FlagDispatchContext020B426C*)obj);
        obj->flags &= ~1;
        obj->bit2 = 0;
    } else if (obj->bit1) {
        obj->flags |= 1;
        UpdateFlagBitsAndDispatch((struct FlagDispatchContext020B426C*)obj);
    } else {
        UpdateFlagBitsAndDispatch((struct FlagDispatchContext020B426C*)obj);
    }
    return 1;
}
