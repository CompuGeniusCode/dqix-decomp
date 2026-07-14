#include <globaldefs.h>

extern unsigned short data_02111224;
extern "C" void func_020c3aac(unsigned int);

#define DATA0 (*(unsigned short *)((char *)&data_02111224 + 0x0))
#define DATA6 (*(unsigned short *)((char *)&data_02111224 + 0x6))

// USA: func_020c44e4
#pragma optimize_for_size off
ARM void SetVramBankFlag020c44e4(int flag) {
    unsigned short combined = (unsigned short)(~flag & (DATA0 | DATA6));
    DATA0 = combined;
    DATA6 = (unsigned short)flag;
    switch (flag) {
    case 0xc:
        *(volatile unsigned char *)0x4000243 = 0x8a;
        *(volatile unsigned char *)0x4000242 = 0x82;
        break;
    case 4:
        *(volatile unsigned char *)0x4000242 = 0x82;
        break;
    case 8:
        *(volatile unsigned char *)0x4000243 = 0x82;
        break;
    case 0:
        break;
    }
    func_020c3aac(DATA0);
}
