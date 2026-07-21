#include <globaldefs.h>

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8 cb);
ARM int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2);
ARM int TransferBg2CharData(int arg0, int arg1, unsigned int arg2);
ARM void CopyToPaletteA(int arg0, int arg1, unsigned int arg2);
ARM int TransferToBgCharBase020c5c58(int arg0, int arg1, unsigned int arg2);

extern unsigned char data_ov031_0224bc94;
extern unsigned char data_ov031_0224bca8;
extern unsigned char data_ov031_0224bcc0;
extern unsigned char data_ov031_0224bcd8;

extern unsigned char data_ov031_0224906c[22];

extern "C" char* func_ov031_02223478(unsigned char* src);
extern "C" void* func_ov031_0223b61c(char* path, unsigned int* outSize, int align);
extern "C" void func_ov031_0223cb68(int channel, int mask);

struct Struct02290cc0_02232568 { char pad0[4]; void** field4; };
extern Struct02290cc0_02232568 data_ov031_02290cc0;

// USA: func_ov031_02232568
extern "C" ARM void func_ov031_02232568(void) {
    unsigned char buf[22];
    unsigned char* dst = buf;
    int count = 11;
    unsigned char* src = data_ov031_0224906c;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    } while (--count);

    func_ov031_022234d8((int)&data_ov031_0224bc94, (Callback_022234d8)TransferMainObjPalette);
    func_ov031_022234d8((int)&data_ov031_0224bca8, (Callback_022234d8)TransferBg2CharData);
    func_ov031_022234d8((int)&data_ov031_0224bcc0, (Callback_022234d8)CopyToPaletteA);
    func_ov031_022234d8((int)&data_ov031_0224bcd8, (Callback_022234d8)TransferToBgCharBase020c5c58);

    char* path = func_ov031_02223478(buf);
    void* ptr = func_ov031_0223b61c(path, 0, 4);
    data_ov031_02290cc0.field4[0] = ptr;
    func_ov031_0223cb68(1, 0x10);

    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
