#include <globaldefs.h>

extern "C" int func_0205b008(int a, void* b, int c, int d, int e, int f);

// USA: func_0205afb0
ARM void SetBitfield0205afb0(int a, void* b, int c) {
    func_0205b008(a, b, 2, 0xf000, 0xc, (unsigned short)(c & 0xf));
}
