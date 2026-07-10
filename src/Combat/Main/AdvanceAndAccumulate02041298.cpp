#include <globaldefs.h>

extern "C" void func_02034d20(void* obj);
extern "C" void func_020412f4(void* obj);
extern "C" void func_02041378(void* obj);

struct Obj02041298 {
    char pad0[0xac];
    unsigned short flags;      /* 0xac */
    char pad1[0x12];           /* 0xae */
    int fieldc0;               /* 0xc0 */
    char pad2[0x10];           /* 0xc4 */
    unsigned char bit0 : 1;    /* 0xd4 */
};

// USA: func_02041298
ARM void AdvanceAndAccumulate02041298(struct Obj02041298* obj, int amount) {
    if (obj->bit0) return;
    func_02034d20(obj);
    if (obj->flags & 0x1) func_020412f4(obj);
    func_02041378(obj);
    if ((obj->flags & 0x1) == 0) {
        obj->fieldc0 = obj->fieldc0 + amount;
    } else {
        obj->fieldc0 = 0;
    }
}
