#include <globaldefs.h>

struct Block48_regtest9 { unsigned int w[12]; };

ARM void TestBigCopy_regtest9(Block48_regtest9* src, Block48_regtest9* dst) {
    *dst = *src;
}
