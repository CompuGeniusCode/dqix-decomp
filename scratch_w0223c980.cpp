#include <globaldefs.h>

struct FlagsPair0223c980 { unsigned char e, f; };

extern "C" void func_020b26e8(void* obj, int u1, int u2, int u3, int a, int b, int c, int d, FlagsPair0223c980 ef);

// USA: func_ov031_0223c980
extern "C" ARM void func_ov031_0223c980(void* obj, int u1, int u2, int u3, int a, int b, int c, int d) {
    void* p = *(void**)((char*)obj + 0x1c);
    FlagsPair0223c980 flags;
    unsigned char* fp = (unsigned char*)&flags;
    unsigned char zeroVal = 0;
    fp[0] = zeroVal;
    fp[1] = zeroVal;
    void* q = *(void**)p;
    void* r = *(void**)((char*)q + 8);
    unsigned char typeByte = *((unsigned char*)r + 7);
    switch (typeByte) {
        case 0: case 7: flags.e = 1; break;
        case 1: case 2: flags.f = 1; break;
        case 3: case 4: flags.e = zeroVal - 1; break;
        case 5: case 6: flags.f = zeroVal - 1; break;
        default: break;
    }
    func_020b26e8((char*)obj + 0x18, u1, u2, u3, a, b, c, d, flags);
}
