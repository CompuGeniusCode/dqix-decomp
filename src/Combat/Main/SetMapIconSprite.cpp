#include <globaldefs.h>

struct Element0202756c {
    char pad0[0xc];
    int fieldC;
    int field10;
    int field14;
    int field18;
    char pad1[4];
    unsigned short field20;
    unsigned char field22;
    char pad2[3];
    unsigned char field26;
};

extern "C" void func_0205afb0(int a, void* b, int c);
extern "C" void func_0205ac40(void* a, void* b);

// Fills in one of the map screen's icon sprites, the 0x28-byte entries at +0xe8, and hands it to
// the cell-animation manager at +0x94; the module's literal pools name tmap_base.pac and
// obj_mm.pac. The first two arguments are screen coordinates in 20.12 fixed point -- only the
// map-scroll path centres them, 0x02026194 adding 0x80000 by 0x60000 -- and the last two are X
// and Y scale with 0x1000 as 1.0. func_0205afb0 writes the seventh into the OBJ attribute-2
// palette field. Slots are fixed by kind: func_02027100 uses combatant id + 1, func_0202720c 0x17.
extern "C" ARM void SetMapIconSprite(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10) {
    struct Element0202756c* elem = (struct Element0202756c*)((char*)obj + 0xe8 + idx * 0x28);
    elem->field14 = p1;
    elem->field18 = p2;
    elem->field22 = p5 & 0x7f;
    elem->field26 = p6 & 0x3;
    if (p7 < 0xf) {
        func_0205afb0((int)((char*)obj + 0x94), elem, p7);
    }
    if (p8 < 0x40) {
        elem->field20 = p8;
    }
    elem->fieldC = p9;
    elem->field10 = p10;
    func_0205ac40((char*)obj + 0x94, elem);
}
