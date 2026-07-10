#include <globaldefs.h>

extern "C" int func_0205b008(int a, void* b, int c, int d, int e, int f);

// USA: func_0205af84
ARM void SetBitfield0205af84(int a, void* b, int c) {
    func_0205b008(a, b, 2, 0xc00, 0xa, (unsigned short)(c & 0x3));
}
