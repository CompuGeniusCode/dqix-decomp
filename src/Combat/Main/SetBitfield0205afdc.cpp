#include <globaldefs.h>

extern "C" int func_0205b008(int a, void* b, int c, int d, int e, int f);

// USA: func_0205afdc
ARM void SetBitfield0205afdc(int a, void* b, int c) {
    func_0205b008(a, b, 0, 0xc00, 0xa, (unsigned short)(c & 0x3));
}
