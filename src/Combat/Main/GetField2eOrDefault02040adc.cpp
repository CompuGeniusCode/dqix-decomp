#include <globaldefs.h>

struct Sub02040adc {
    char unk[0x2e];
    short value;
};

struct Obj02040adc {
    char unk[0x14];
    struct Sub02040adc* sub;
};

// USA: func_02040adc
ARM int GetField2eOrDefault02040adc(struct Obj02040adc* obj) {
    struct Sub02040adc* sub = obj->sub;
    if (sub != 0) {
        return sub->value;
    }
    return 0x3d;
}
