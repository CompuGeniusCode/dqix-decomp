#include <globaldefs.h>

typedef void (*Callback0220ef9c)(void*, void*, void*, unsigned short);

struct GuardStruct_0220ef9c {
    char pad0[0x28];
    Callback0220ef9c cb28;
};

extern struct GuardStruct_0220ef9c data_ov031_0224e540;

// USA: func_ov031_0220ef9c
ARM void CallCallback28_0220ef9c(char *arg) {
    Callback0220ef9c cb = data_ov031_0224e540.cb28;
    if (cb == 0) {
        return;
    }
    unsigned short v = *(unsigned short*)(arg + 0x6);
    cb(arg + 0x1e, arg + 0x18, arg + 0x2c, v);
}
