#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
typedef unsigned char (*GetByteFn02184c30)(struct TaggedNumber02184c30*);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

// USA: func_ov011_021864b0
extern "C" ARM int func_ov011_021864b0(struct TaggedNumber02184c30* args) {
    int mode = GetTaggedValueAsInt_02184c30(&args[0]);
    unsigned char a = ((GetByteFn02184c30)GetTaggedValueAsInt_02184c30)(&args[1]);
    unsigned char b = ((GetByteFn02184c30)GetTaggedValueAsInt_02184c30)(&args[2]);
    unsigned char c = ((GetByteFn02184c30)GetTaggedValueAsInt_02184c30)(&args[3]);
    int d = GetTaggedValueAsInt_02184c30(&args[4]);
    if (mode == 0) {
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, a, b, c, d);
    } else if (mode == 1) {
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4001050, a, b, c, d);
    }
    return 1;
}
