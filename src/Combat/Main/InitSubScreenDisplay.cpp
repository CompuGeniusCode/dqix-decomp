#include <globaldefs.h>

void ProcessFlagWord02111238(void);
int func_020c4ac0(void);
void SetSubBgMode(unsigned int mode);
void SetVramFieldAndDispatch020c4658(unsigned short value);
extern "C" void func_020c45b0(int);
void SetSubBg0Control02020968(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void SetSubBg1Control0202099c(int screenSize, int colorMode, int screenBase, int charBase, int bit13);

// USA: func_020209d0
ARM void InitSubScreenDisplay(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;

    ProcessFlagWord02111238();
    func_020c4ac0();
    SetSubBgMode(0);

    *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;
    SetVramFieldAndDispatch020c4658(0x100);

    *dispcnt = (*dispcnt & 0xffcfffef) | 0x10;
    func_020c45b0(0x80);

    SetSubBg0Control02020968(0, 0, 0xe, 0, 0);
    SetSubBg1Control0202099c(0, 0, 0xf, 0, 0);

    unsigned short* bgcnt = (unsigned short*)0x4001008;
    bgcnt[0] = (bgcnt[0] & ~3) | 1;
    bgcnt[1] = (bgcnt[1] & ~3);
    bgcnt[2] = (bgcnt[2] & ~3) | 2;
    bgcnt[3] = (bgcnt[3] & ~3) | 3;
}
