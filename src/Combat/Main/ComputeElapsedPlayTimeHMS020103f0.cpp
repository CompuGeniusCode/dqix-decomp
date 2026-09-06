#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long a, unsigned long long b);
extern "C" unsigned int _ull_mod(unsigned long long a, unsigned long long b);

struct TimeStamp020103f0 {
    unsigned char pad0[0x3e8];
    long long stamp;   // 0x3e8
};

// USA: func_020103f0
ARM void ComputeElapsedPlayTimeHMS020103f0(TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds) {
    unsigned long long elapsed = _ll_udiv(GetCurrentTimestamp() << 6, 0x1ff6210)
                                - _ll_udiv(obj->stamp << 6, 0x1ff6210);
    unsigned long long hours = _ll_udiv(elapsed, 3600);
    unsigned int minutes = _ull_mod(_ll_udiv(elapsed, 60), 60);
    unsigned int seconds = _ull_mod(elapsed, 60);
    if (hours > 10000) hours = 9999;
    *outHours = (unsigned short)hours;
    *outMinutes = minutes;
    *outSeconds = seconds;
}
