#include <globaldefs.h>

struct Element020de650 {
    unsigned int v[8];
};

struct Container020de650 {
    unsigned short count;
    unsigned char pad[10];
    struct Element020de650* base;
};

typedef int (*KeyFunc020de650)(struct Element020de650*);

extern "C" int func_020de56c(void*);
extern "C" struct Element020de650* func_020de650(struct Container020de650* c, int key, KeyFunc020de650 fn);

struct Container020dedd0 {
    unsigned short count;          // 0x0
    unsigned char pad[10];         // 0x2
    struct Element020de650* base;  // 0xc
    unsigned char pad2[4];         // 0x10
    unsigned char useBinarySearch; // 0x14
};

// Finds an item's record by id. The tables these containers wrap come from data/prm/itemdt.gp2
// (member itemdt_<LG>.nat) via several builders -- func_0207d6dc, func_02016804, func_0201b53c and
// others -- while ov000 wraps itemdt_w.gp2 instead; the records are 0x20 bytes with the id as the
// halfword at +0x18. When the flag at +0x14 is set the shared binary search runs instead of the
// linear scan, so it seems to mark the table as already sorted. ov003 reads +0x1a of the result as
// a unit price against the 9,999,999 gold cap, and ov002 keys the call with an inventory item id.
extern "C" ARM struct Element020de650* FindItemRecordById(struct Container020dedd0* c, int key) {
    int i;
    struct Element020de650* elem;
    unsigned short count;
    if (key < 0) {
        return NULL;
    }
    if (c->useBinarySearch != 0) {
        return func_020de650((struct Container020de650*)c, key, (KeyFunc020de650)func_020de56c);
    }
    elem = c->base;
    if (elem == NULL || (KeyFunc020de650)func_020de56c == NULL) {
        elem = NULL;
        goto done;
    }
    count = c->count;
    if (count == 0) {
        elem = NULL;
        goto done;
    }
    for (i = 0; i < count; i++, elem++) {
        if (key == func_020de56c(elem)) {
            goto done;
        }
    }
    elem = NULL;
done:
    return elem;
}
