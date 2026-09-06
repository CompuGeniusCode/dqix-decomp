#include <globaldefs.h>

struct TweenObj0203b250 {
    char pad0[0x24];
    unsigned char flag24;
    unsigned char flag25;
};

extern "C" void func_0203b110(struct TweenObj0203b250*, int, int);

// USA: func_0203b250
ARM void SetChannelFlag0x24AfterUpdate(struct TweenObj0203b250* obj, int a, int b) {
    func_0203b110(obj, a, b);
    obj->flag24 = 1;
}
