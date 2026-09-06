#include <globaldefs.h>

struct CombatSlots0206b198;
void DecrementSlotRef0206b198(struct CombatSlots0206b198* obj, unsigned short idx);
ARM bool IsHighByteFF02044494(void* obj, void* src);
int Dispatch02044420(void* obj, void* src);

struct Combat0206b104 {
    char pad0[0x4c];
    unsigned short* arr;
    char pad50[0x54 - 0x50];
    int f54;
    int f58;
    char pad5c[0x6c - 0x5c];
    int count;
    int f70;
    int f74;
    int f78;
    char pad7c[0x88 - 0x7c];
    int idx;
};

// USA: func_0206b104  (semantic: ProcessSlotSequence0206b104)
extern "C" ARM void func_0206b104(struct Combat0206b104* obj) {
    if (obj->f54 == 0 || obj->f58 == 0) return;
    if (obj->count == 0) return;
    unsigned short* p;
    unsigned int i = obj->idx;
    for (; i < obj->count; i++) {
        p = obj->arr + i;
        if (IsHighByteFF02044494(obj, p)) {
            i += Dispatch02044420(obj, p);
        } else {
            DecrementSlotRef0206b198((struct CombatSlots0206b198*)obj, *p);
        }
    }
    obj->count = 0;
    obj->f70 = 0;
    obj->f74 = 0;
    obj->f78 = 0;
}
