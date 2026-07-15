#include <globaldefs.h>

struct Buf3Words_0215e300 { unsigned int w[3]; };
extern "C" void func_0200f374(void* buf, int size);

// USA: func_ov004_0215e300
ARM void CopyThreeWords_0215e300(Buf3Words_0215e300* dst) {
    Buf3Words_0215e300 tmp;
    func_0200f374(&tmp, sizeof(tmp));
    *dst = tmp;
}
