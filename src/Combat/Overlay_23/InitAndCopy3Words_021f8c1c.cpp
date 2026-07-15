#include <globaldefs.h>

extern "C" void func_0200f374(void*, int);

struct Buf3W021f8c1c { unsigned int w[3]; };

// USA: func_ov023_021f8c1c
ARM void InitAndCopy3Words_021f8c1c(void* dst) {
    Buf3W021f8c1c buf;
    func_0200f374(&buf, 0xc);
    *(Buf3W021f8c1c*)dst = buf;
}
