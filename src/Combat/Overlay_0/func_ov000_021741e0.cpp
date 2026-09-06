#include <globaldefs.h>

extern "C" int fix32_Divide(unsigned int numerHi, unsigned int denomLo);
extern "C" void func_0205ac40(void* dst, void* src);

struct Entry021741e0 {
    char pad0[0xc];
    int field0c;
    int field10;
    int field14;
    int field18;
    char pad1[0x20 - 0x1c];
    unsigned short field20;
    unsigned char field22;
    char pad2[0x26 - 0x23];
    unsigned char field26;
    char pad3[0x28 - 0x27];
};

// USA: func_ov000_021741e0  (semantic: InitMovingSlotEntry_021741e0)
extern "C" ARM void func_ov000_021741e0(void* obj, float maxSpeed, float speed, int x, int argE,
    unsigned char slotIdx, unsigned char byteG, unsigned char byteH, unsigned char byteI, unsigned char flagJ) {
    float minVal = maxSpeed;
    if (speed < maxSpeed) minVal = speed;

    struct Entry021741e0* base = *(struct Entry021741e0**)((char*)obj + 0x170);
    struct Entry021741e0* e = base + slotIdx;
    int fixedX = x << 0xc;
    int fixedArgE = argE << 0xc;

    int fixedSpeed = (int)(4096.0f * minVal);
    long long wide = ((long long)fixedSpeed << 16) + 0x800;
    int val2 = (int)(wide >> 12);
    if (flagJ) val2 += 0x1000;
    val2 &= ~0xfff;
    int divResult = fix32_Divide(val2, 0x10000);

    if (divResult < 0x41) {
        if (0.0f < minVal) {
            divResult = 0x41;
        } else {
            return;
        }
    }

    e->field14 = fixedX;
    e->field18 = fixedArgE;
    e->field0c = divResult;
    e->field10 = 0x1000;
    e->field20 = byteH;
    e->field22 = byteG;
    e->field26 = byteI;
    func_0205ac40((char*)obj + 0x11c, e);
}
