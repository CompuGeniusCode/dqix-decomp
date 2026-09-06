#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void DisableSubObjVRAMBanks(void);
extern "C" int DisableSubBGVRAMBanks(void);
void SetSubBgMode(unsigned int mode);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void _Z24SetSubBg0Control02020968iiiii(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void _Z24SetSubBg1Control0202099ciiiii(int screenSize, int colorMode, int screenBase, int charBase, int bit13);

struct SubScreenState02020838 {
    unsigned char pad[0xc];
    unsigned char mode : 4;
};

// USA: func_02020838
extern "C" ARM void func_02020838(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    SubScreenState02020838* state = *(SubScreenState02020838**)((char*)func_02012fe4() + 8);

    DisableSubBGVRAMBanks();
    DisableSubObjVRAMBanks();
    SetSubBgMode(0);
    MapVRAMBanksToSubBG(0x80);

    if (state->mode == 0) {
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1100;
        _Z24SetSubBg0Control02020968iiiii(0, 0, 0xf, 0, 0);
        _Z24SetSubBg1Control0202099ciiiii(0, 0, 0x10, 0, 0);
    } else {
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;
        _Z24SetSubBg0Control02020968iiiii(1, 0, 0xe, 0, 0);
        _Z24SetSubBg1Control0202099ciiiii(0, 0, 0xd, 0, 0);
    }

    MapVRAMBanksToSubObj(0x100);

    *dispcnt = (*dispcnt & 0xffcfffef) | 0x10;

    unsigned short* bgcnt = (unsigned short*)0x4001008;
    bgcnt[0] = (bgcnt[0] & ~3) | 1;
    bgcnt[1] = (bgcnt[1] & ~3) | 2;
    bgcnt[2] = (bgcnt[2] & ~3);
    bgcnt[3] = (bgcnt[3] & ~3) | 3;
}
