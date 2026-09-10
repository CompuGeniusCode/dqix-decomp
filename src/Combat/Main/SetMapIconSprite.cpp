#include <globaldefs.h>

struct SpriteCell {
    char unknown0[0xc];
    int scaleX;
    int scaleY;
    int x;
    int y;
    char unknown1c[4];
    unsigned short unknown20;
    unsigned char unknown22;
    char unknown23[3];
    unsigned char unknown26;
};

extern "C" void func_0205afb0(int cellGraphics, void* cell, int palette);
extern "C" void func_0205ac40(void* cellGraphics, void* cell);

// Fills in one of the map screen's icon sprites, the 0x28-byte cells at +0xe8, and hands it to
// the cell-animation manager at +0x94; the module's literal pools name tmap_base.pac and
// obj_mm.pac. The first two arguments are screen coordinates in 20.12 fixed point -- only the
// map-scroll path centres them, 0x02026194 adding 0x80000 by 0x60000 -- and the last two are X
// and Y scale with 0x1000 as 1.0, which is how func_0208baec builds the same pair, from one float
// times 4096. func_0205afb0 writes the seventh into the OBJ attribute-2 palette field. Slots are
// fixed by kind: func_02027100 uses combatant id + 1, func_0202720c 0x17. The fields at +0x20,
// +0x22 and +0x26 are set from per-kind bases -- +0x22 is 0x3c plus the combatant id in
// func_02027100, 0x40 in func_0202720c and 0x48 plus the slot in func_ov000_021811f4, and
// func_0205addc copies one animation record byte into it -- but func_0205ac40, the function every
// writer hands the finished cell to, is not decompiled, so none of the three is established.
extern "C" ARM void SetMapIconSprite(void* mapScreen, int screenX, int screenY, int idx,
        unsigned char unknown22, unsigned char unknown26, unsigned short palette, unsigned char unknown20, int scaleX, int scaleY) {
    struct SpriteCell* cell = (struct SpriteCell*)((char*)mapScreen + 0xe8 + idx * 0x28);
    cell->x = screenX;
    cell->y = screenY;
    cell->unknown22 = unknown22 & 0x7f;
    cell->unknown26 = unknown26 & 0x3;
    if (palette < 0xf) {
        func_0205afb0((int)((char*)mapScreen + 0x94), cell, palette);
    }
    if (unknown20 < 0x40) {
        cell->unknown20 = unknown20;
    }
    cell->scaleX = scaleX;
    cell->scaleY = scaleY;
    func_0205ac40((char*)mapScreen + 0x94, cell);
}
