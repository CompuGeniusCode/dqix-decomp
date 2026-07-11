#include <globaldefs.h>

extern "C" long long func_020c8d5c(void);
extern "C" long long func_0200cedc(long long a, long long b);

struct TimeStamp020105a8 {
    unsigned char pad0[0x3e8];
    long long stamp;   // 0x3e8
};

// USA: func_020105a8
ARM void ComputeElapsedTime020105a8(TimeStamp020105a8* obj, int* out) {
    *out = (int)(func_0200cedc(func_020c8d5c() << 6, 0x1ff6210)
               - func_0200cedc(obj->stamp << 6, 0x1ff6210));
}
