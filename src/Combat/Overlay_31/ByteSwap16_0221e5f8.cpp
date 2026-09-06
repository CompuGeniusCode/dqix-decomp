#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_ov031_0221e5f8  (semantic: ByteSwap16_0221e5f8)
extern "C" THUMB unsigned short func_ov031_0221e5f8(short value) {
    return (unsigned short)((unsigned char)(value >> 8) | ((value << 8) & 0xff00));
}
