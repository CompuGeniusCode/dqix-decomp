#include <globaldefs.h>

int ResetVramBanks02111226();
int ResetVramBanks02111228();
void func_020c4ac0();
void ProcessFlagWord02111238(void);
extern "C" void func_ov031_0223df4c();
extern "C" void func_020c3b64(int v);
void SetVramBankAndDispatch020c3df4(int mode);
void SetPowerRegisterMode020c3f44(int mode);
void SetVramBankFlag020c4044(unsigned int flag);
extern "C" void func_020c40f0(int v);
void SetVramFieldAndDispatch020c42c8(int value);
void SetVramBankAndDispatch020c43b0(int mode);
extern "C" void func_020c45b0(int v);
void SetVramFieldAndDispatch020c4658(unsigned short value);
void SetSubBgExtPaletteFieldAndDispatch020c46c8(unsigned short value);
void SetSubObjExtPaletteFieldAndDispatch020c4748(unsigned short value);
void EnableVramBanksByMask(unsigned short mask);

struct VramInitBlock_02290d68 {
    int field0, field4, field8, fieldc, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30;
};
extern VramInitBlock_02290d68 data_ov031_02290d68;

typedef void (*IntFn)(int);

// USA: func_ov031_0223de5c
extern "C" ARM void func_ov031_0223de5c() {
    ResetVramBanks02111226();
    ResetVramBanks02111228();
    func_020c4ac0();
    ProcessFlagWord02111238();
    func_ov031_0223df4c();

    func_020c3b64(data_ov031_02290d68.field0);
    SetVramBankAndDispatch020c3df4(data_ov031_02290d68.field4);
    SetPowerRegisterMode020c3f44(data_ov031_02290d68.field8);
    SetVramBankFlag020c4044(data_ov031_02290d68.fieldc);
    func_020c40f0(data_ov031_02290d68.field10);
    SetVramFieldAndDispatch020c42c8(data_ov031_02290d68.field14);
    SetVramBankAndDispatch020c43b0(data_ov031_02290d68.field18);
    func_020c45b0(data_ov031_02290d68.field1c);
    ((IntFn)SetVramFieldAndDispatch020c4658)(data_ov031_02290d68.field20);
    ((IntFn)SetSubBgExtPaletteFieldAndDispatch020c46c8)(data_ov031_02290d68.field24);
    ((IntFn)SetSubObjExtPaletteFieldAndDispatch020c4748)(data_ov031_02290d68.field28);
    ((IntFn)EnableVramBanksByMask)(data_ov031_02290d68.field30);

    *(volatile unsigned short *)0x4000050 = 0;
    *(volatile unsigned short *)0x4001050 = 0;
    *(volatile unsigned int *)0x4000010 = 0;
    *(volatile unsigned int *)0x4000014 = 0;
    *(volatile unsigned int *)0x4000018 = 0;
    *(volatile unsigned int *)0x400001c = 0;
    *(volatile unsigned int *)0x4001010 = 0;
    *(volatile unsigned int *)0x4001014 = 0;
    *(volatile unsigned int *)0x4001018 = 0;
    *(volatile unsigned int *)0x400101c = 0;
}
