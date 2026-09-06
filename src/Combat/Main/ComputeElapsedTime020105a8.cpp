#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" long long _ll_udiv(long long a, long long b);

struct TimeStamp020105a8 {
    unsigned char pad0[0x3e8];
    long long stamp;   // 0x3e8
};

// USA: func_020105a8
ARM void ComputeElapsedTime020105a8(TimeStamp020105a8* obj, int* out) {
    *out = (int)(_ll_udiv(GetCurrentTimestamp() << 6, 0x1ff6210)
               - _ll_udiv(obj->stamp << 6, 0x1ff6210));
}
