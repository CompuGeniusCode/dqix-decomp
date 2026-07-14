#include <globaldefs.h>

int IsHalfwordInRange02067ad8(int unused, void* src);
bool IsHighByteFF02044494(void* obj, void* src);
int Dispatch02044420(void* obj, void* src);

struct CombatSlots0206b198;
void DecrementSlotRef0206b198(struct CombatSlots0206b198* obj, unsigned short idx);

struct Ctx0206b61c {
    unsigned char pad0[0x4c];
    unsigned short* buf;
    unsigned char pad1[0x74 - 0x50];
    int idx;
    int counter;
};

// USA: func_0206b61c
ARM void ProcessTextTokens0206b61c(struct Ctx0206b61c* obj) {
    int cont = 1;
    int consumed = 0;
    int stop = consumed;
    unsigned short* p = obj->buf + obj->idx;
    while (cont) {
        int extra;
        if (IsHalfwordInRange02067ad8((int)obj, p)) {
            cont = stop;
        }
        if (IsHighByteFF02044494(obj, p)) {
            extra = Dispatch02044420(obj, p);
            p += extra;
            consumed += extra;
        } else {
            DecrementSlotRef0206b198((struct CombatSlots0206b198*)obj, *p);
        }
        p += 1;
        consumed += 1;
    }
    obj->idx += consumed;
    obj->counter += 1;
}
