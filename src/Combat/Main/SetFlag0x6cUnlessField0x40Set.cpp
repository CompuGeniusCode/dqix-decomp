#include <globaldefs.h>

struct Bits40_37464;
int GetField0x40Bits3To7(struct Bits40_37464* obj);
int SetFlag0x6cBit0(unsigned char* obj);
extern "C" void func_02076a8c(void* p);

// USA: func_02078660
ARM int SetFlag0x6cUnlessField0x40Set(void* p) {
    int r = GetField0x40Bits3To7((struct Bits40_37464*)p);
    if (r != 0) return r;
    func_02076a8c(p);
    return SetFlag0x6cBit0((unsigned char*)p);
}
