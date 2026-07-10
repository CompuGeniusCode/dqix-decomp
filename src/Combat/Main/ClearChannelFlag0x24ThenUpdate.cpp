#include <globaldefs.h>

struct TweenObj0203b2b8 {
    char pad0[0x24];
    unsigned char flag24;
    unsigned char flag25;
};

extern "C" void func_0203b110(struct TweenObj0203b2b8*, int, int);

// USA: func_0203b2b8
ARM void ClearChannelFlag0x24ThenUpdate(struct TweenObj0203b2b8* obj, int a, int b) {
    obj->flag24 = 0;
    func_0203b110(obj, a, b);
}
