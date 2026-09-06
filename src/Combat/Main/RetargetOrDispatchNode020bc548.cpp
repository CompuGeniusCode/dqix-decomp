#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Obj020bc6fc;
void DispatchType2Command020bc6fc(struct Obj020bc6fc*);

struct Tween020c0260;
void RetargetTween020c0204(struct Tween020c0260*, int, int);

void RelinkAllocatorAndSetByte3d020bc870(SignedAllocatorHeader*, unsigned char);

struct Obj020bc548 {
    char pad0[0x2c];
    unsigned char field2c;
};

// USA: func_020bc548  (semantic: RetargetOrDispatchNode020bc548)
extern "C" ARM void func_020bc548(struct Obj020bc548* obj, int flag) {
    if (obj == 0 || obj->field2c == 0) return;
    if (flag == 0) {
        DispatchType2Command020bc6fc((struct Obj020bc6fc*)obj);
        return;
    }
    RetargetTween020c0204((struct Tween020c0260*)((char*)obj + 0x1c), 0, flag);
    RelinkAllocatorAndSetByte3d020bc870((SignedAllocatorHeader*)obj, 0);
    obj->field2c = 2;
}
