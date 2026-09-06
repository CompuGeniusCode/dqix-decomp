#include <globaldefs.h>

struct TweenObj0203b2cc {
    char pad0[0x24];
    unsigned char flag24;
    unsigned char flag25;
};

extern "C" void func_0203b19c(struct TweenObj0203b2cc*, int, int);

// USA: func_0203b2cc
ARM void ClearChannelFlag0x25ThenUpdate(struct TweenObj0203b2cc* obj, int a, int b) {
    obj->flag25 = 0;
    func_0203b19c(obj, a, b);
}
