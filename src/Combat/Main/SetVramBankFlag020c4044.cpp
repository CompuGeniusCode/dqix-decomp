#include <globaldefs.h>

extern unsigned short data_02111224;
extern "C" void func_020c3aac(unsigned int);

#define DATA0 (*(unsigned short *)((char *)&data_02111224 + 0x0))
#define DATA10 (*(unsigned short *)((char *)&data_02111224 + 0x10))

// USA: func_020c4044
#pragma optimize_for_size off
ARM void SetVramBankFlag020c4044(unsigned int flag) {
    unsigned short combined = (unsigned short)(~flag & (DATA0 | DATA10));
    DATA0 = combined;
    DATA10 = (unsigned short)flag;
    switch (flag) {
    case 0x20:
        *(volatile unsigned int *)0x4000000 |= 0x80000000;
        *(volatile unsigned char *)0x4000245 = 0x85;
        break;
    case 0x40:
        *(volatile unsigned int *)0x4000000 |= 0x80000000;
        *(volatile unsigned char *)0x4000246 = 0x85;
        break;
    case 0:
        *(volatile unsigned int *)0x4000000 &= ~0x80000000;
        break;
    }
    func_020c3aac(DATA0);
}
