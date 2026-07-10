#include <globaldefs.h>

struct Actor02085a48 {
    char pad0[0x2ac];
    short field2ac;
    char pad1[0x304 - 0x2ae];
    int field304;
};

// USA: func_02085a48
ARM float GetField0x304ScaleLow(struct Actor02085a48* actor) {
    if (actor->field2ac <= 0) {
        return 1.0f;
    }
    return (float)((actor->field304 << 26) >> 26) / 10.0f;
}
