#include <globaldefs.h>

extern "C" void func_0202ab34(void* data, int a, int b);
void CopyToPaletteA(int src, int dstOffset, unsigned int size);
extern "C" void func_020ca458(int a, void* ptr, int size);

extern char data_020ef788;
extern char data_020ef78b;
extern char data_020ef78e;
extern char data_020ef791;
extern char data_020ef794;
extern char data_020ef797;
extern char data_020ef79a;
extern char data_020e7170;
extern char data_020fe9cc;

// USA: func_0202ac74
ARM void InitPaletteTables0202ac74() {
    func_0202ab34(&data_020ef788, 0x2, 0x28);
    func_0202ab34(&data_020ef78b, 0xc, 0x30);
    func_0202ab34(&data_020ef78e, 0x1, 0x3d);
    func_0202ab34(&data_020ef791, 0x1a, 0x41);
    func_0202ab34(&data_020ef794, 0x1a, 0x2f);
    func_0202ab34(&data_020ef797, 0x1, 0x2e);
    func_0202ab34(&data_020ef79a, 0x1, 0x2d);
    CopyToPaletteA((int)&data_020e7170, 0, 0x200);
    func_020ca458(0, &data_020fe9cc, 0x600);
}
