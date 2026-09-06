#include <globaldefs.h>

struct Actor02085a80 {
    char pad0[0x2ac];
    short field2ac;
    char pad1[0x304 - 0x2ae];
    int field304;
};

// USA: func_02085a80
ARM float GetField0x304ScaleMid(struct Actor02085a80* actor) {
    if (actor->field2ac <= 0) {
        return 1.0f;
    }
    return (float)((actor->field304 << 20) >> 26) / 10.0f;
}
