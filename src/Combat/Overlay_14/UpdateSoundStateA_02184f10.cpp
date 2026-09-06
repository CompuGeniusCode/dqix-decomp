#include <globaldefs.h>

struct SoundState02184f10 {
    char pad0[0x48];
    int f48;
    int f4c;
    int f50;
    int f54;
    char pad1[0x7c - 0x58];
    unsigned char f7c;
    char pad2[0x81 - 0x7d];
    unsigned char f81;
};

extern "C" void func_ov014_02184f78(struct SoundState02184f10* obj, int a, int b, int flag);

// USA: func_ov014_02184f10
ARM void UpdateSoundStateA_02184f10(struct SoundState02184f10* o, int a, int b) {
    if (!o->f7c) {
        return;
    }
    if (o->f4c != o->f48) {
        o->f4c = o->f48;
        o->f54 = o->f50;
        o->f81 |= 0x20;
    }
    if (a == 0 || b == 0) {
        o->f48 = a;
        return;
    }
    if (o->f48 == a || o->f50 == b) {
        return;
    }
    func_ov014_02184f78(o, a, b, 1);
}
