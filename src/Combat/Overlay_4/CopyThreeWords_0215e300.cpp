#include <globaldefs.h>

struct Buf3Words_0215e300 { unsigned int w[3]; };
extern "C" void __clear(void* buf, int size);

// USA: func_ov004_0215e300
ARM void CopyThreeWords_0215e300(Buf3Words_0215e300* dst) {
    Buf3Words_0215e300 tmp;
    __clear(&tmp, sizeof(tmp));
    *dst = tmp;
}
