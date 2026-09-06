#include <globaldefs.h>

struct TweenObj0203b268 {
    char pad0[0x24];
    unsigned char flag24;
    unsigned char flag25;
};

extern "C" void func_0203b19c(struct TweenObj0203b268*, int, int);

// USA: func_0203b268
ARM void SetChannelFlag0x25AfterUpdate(struct TweenObj0203b268* obj, int a, int b) {
    func_0203b19c(obj, a, b);
    obj->flag25 = 1;
}
