#include <globaldefs.h>

struct SlotEntry02039fec {
    unsigned char pad0[5];
    signed char timer;
    unsigned char pad6[2];
    short velocity;
    short position;
    unsigned char pad0xc[0xc];
};

struct Obj02039fec {
    unsigned char pad0[0x550];
    struct SlotEntry02039fec slots[16];
    int cursor;
    int limit;
};

extern "C" void func_0203a5e8(struct Obj02039fec* obj, int index);

// USA: func_02039fec
ARM void ProcessSlotDamping02039fec(struct Obj02039fec* obj) {
    int i = obj->cursor;
    while (i != obj->limit) {
        struct SlotEntry02039fec* e = &obj->slots[i];
        e->position += e->velocity;
        e->velocity = e->velocity + ((0x1000 - e->position) >> 1);
        e->velocity = (short)(0.8f * e->velocity);
        e->timer--;
        if (e->timer <= 0) {
            int next = i + 1;
            obj->cursor = next;
            if (next >= 16) obj->cursor = 0;
        } else if (e->timer == 0x22) {
            func_0203a5e8(obj, i);
        }
        i++;
        if (i >= 16) i = 0;
    }
}
