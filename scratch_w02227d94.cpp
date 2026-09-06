#include <globaldefs.h>

extern "C" ARM void func_ov031_02235c18(void);
extern "C" ARM void func_ov031_022275e0(void);
ARM void AllocArray_022236e8(void);
extern "C" ARM void func_ov031_0222390c(void);
ARM void ClearByteFlag_02223358(void);
ARM unsigned char GetField0_02227548(void);
ARM int TestFieldRestBits_02227570(unsigned int mask);

struct RetStruct02227630_02227d94;
extern "C" ARM RetStruct02227630_02227d94* func_ov031_02227630(void*);
extern RetStruct02227630_02227d94* data_ov031_02290c4c;

extern char data_ov031_0224b714;
extern void* data_ov031_0224b6f8[];

char* func_ov031_02223478(unsigned char* src);
extern unsigned char data_ov031_0224b724;
extern unsigned char data_ov031_0224b738;
ARM void SetArrayD2c_0223bd58(int idx, int val);

typedef void (*Callback_022234d8_02227d94)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8_02227d94 cb);

extern char data_ov031_0224b74c;
ARM int TransferSubBg1CharData(int, int, unsigned int);
extern char data_ov031_0224b760;
ARM int CopyToPaletteB(int, int, unsigned int);
extern char data_ov031_0224b774;
extern "C" int func_020c5a80(int, int, unsigned int);
extern char data_ov031_0224b78c;
ARM int TransferSubObjPalette(int, int, unsigned int);
extern char data_ov031_0224b7a4;
ARM int TransferBg2CharData(int, int, unsigned int);
extern char data_ov031_0224b7bc;
ARM int CopyToPaletteA(int, int, unsigned int);
extern char data_ov031_0224b7d4;
extern "C" int func_020c5a28(int, int, unsigned int);
extern char data_ov031_0224b7ec;
ARM int TransferMainObjPalette(int, int, unsigned int);

ARM unsigned int GetField8Low4_02227558(void);
extern char data_ov031_0224b804;
extern char data_ov031_0224b818;
ARM int TransferToSubBg1ScreenBase(int, int, unsigned int);

extern "C" ARM void func_ov031_0223cb68(int channel, int mask);
extern "C" ARM void func_ov031_02227f74(void);
ARM void SetField_022274c0_022274c0(int v);

struct BldCnt_02227d94 {
    unsigned short lowbits : 2;
    unsigned short rest : 14;
};

// USA: func_ov031_02227d94
extern "C" ARM void func_ov031_02227d94() {
    func_ov031_02235c18();
    func_ov031_022275e0();
    AllocArray_022236e8();
    func_ov031_0222390c();
    ClearByteFlag_02223358();

    void* a0;
    if (GetField0_02227548() == 1 && TestFieldRestBits_02227570(2)) {
        a0 = &data_ov031_0224b714;
    } else {
        a0 = data_ov031_0224b6f8[GetField0_02227548()];
    }
    data_ov031_02290c4c = func_ov031_02227630(a0);

    SetArrayD2c_0223bd58(1, (int)func_ov031_02223478(&data_ov031_0224b724));
    SetArrayD2c_0223bd58(0, (int)func_ov031_02223478(&data_ov031_0224b738));

    func_ov031_022234d8((int)&data_ov031_0224b74c, (Callback_022234d8_02227d94)TransferSubBg1CharData);
    func_ov031_022234d8((int)&data_ov031_0224b760, (Callback_022234d8_02227d94)CopyToPaletteB);
    func_ov031_022234d8((int)&data_ov031_0224b774, (Callback_022234d8_02227d94)func_020c5a80);
    func_ov031_022234d8((int)&data_ov031_0224b78c, (Callback_022234d8_02227d94)TransferSubObjPalette);
    func_ov031_022234d8((int)&data_ov031_0224b7a4, (Callback_022234d8_02227d94)TransferBg2CharData);
    func_ov031_022234d8((int)&data_ov031_0224b7bc, (Callback_022234d8_02227d94)CopyToPaletteA);
    func_ov031_022234d8((int)&data_ov031_0224b7d4, (Callback_022234d8_02227d94)func_020c5a28);
    func_ov031_022234d8((int)&data_ov031_0224b7ec, (Callback_022234d8_02227d94)TransferMainObjPalette);

    unsigned int f8 = GetField8Low4_02227558();
    if (f8 == 0) {
        func_ov031_022234d8((int)&data_ov031_0224b804, (Callback_022234d8_02227d94)TransferToSubBg1ScreenBase);
    } else if (f8 == 1) {
        func_ov031_022234d8((int)&data_ov031_0224b818, (Callback_022234d8_02227d94)TransferToSubBg1ScreenBase);
    }

    volatile BldCnt_02227d94* sub = (volatile BldCnt_02227d94*)0x400100a;
    volatile BldCnt_02227d94* main_ = (volatile BldCnt_02227d94*)0x400000a;
    sub->lowbits = 3;
    main_->lowbits = 3;
    main_->lowbits = 3;

    func_ov031_0223cb68(1, 2);
    func_ov031_0223cb68(0, 2);
    SetField_022274c0_022274c0((int)func_ov031_02227f74);
}
