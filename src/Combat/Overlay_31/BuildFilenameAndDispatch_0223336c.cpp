#include <globaldefs.h>

extern unsigned char data_ov031_02249118[22];

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern "C" void _Z19TransferBg2CharDataiij(int, int, unsigned int);
extern "C" void _Z14CopyToPaletteAiij(int, int, unsigned int);
extern "C" void _Z28TransferToBgCharBase020c5c58iij(int, int, unsigned int);

extern int data_ov031_0224bd04;
extern int data_ov031_0224bd1c;
extern int data_ov031_0224bd34;

extern "C" const char* func_ov031_02223478(const char* a0);
extern "C" void* func_ov031_0223b61c(const char* path, unsigned int* outSize, int fallback);

struct DataOv02290cc8_0223336c { unsigned char field0; signed char field1; unsigned char field2; int field4; };
extern DataOv02290cc8_0223336c data_ov031_02290cc8;

// USA: func_ov031_0223336c  (semantic: BuildFilenameAndDispatch_0223336c)
extern "C" ARM void func_ov031_0223336c(void) {
    char buf[24];
    int n = 11;
    char* dst = buf;
    unsigned char* src = data_ov031_02249118;
    do {
        unsigned char a = src[0];
        unsigned char b = src[1];
        src += 2;
        dst[0] = a;
        dst[1] = b;
        dst += 2;
        n--;
    } while (n != 0);

    func_ov031_022234d8((int)&data_ov031_0224bd04, (Callback_022234d8)_Z19TransferBg2CharDataiij);
    func_ov031_022234d8((int)&data_ov031_0224bd1c, (Callback_022234d8)_Z14CopyToPaletteAiij);
    func_ov031_022234d8((int)&data_ov031_0224bd34, (Callback_022234d8)_Z28TransferToBgCharBase020c5c58iij);

    const char* name = func_ov031_02223478(buf);
    void* result = func_ov031_0223b61c(name, 0, 4);
    data_ov031_02290cc8.field4 = (int)result;

    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
