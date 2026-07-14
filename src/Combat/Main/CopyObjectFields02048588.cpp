#include <globaldefs.h>

extern "C" void func_02036d88(void* self);
int GetIntAt0x6c(unsigned char* obj);
void SetBitsInField0x6c(unsigned char* obj, unsigned int mask);

struct TargetObj02048588 {
    unsigned char pad[0x10];
    unsigned int lowBits : 27;
    unsigned int flag27 : 1;
    unsigned int highBits : 4;
};

// USA: func_02048588
ARM void CopyObjectFields02048588(unsigned char* self, unsigned char* dst) {
    func_02036d88(self);
    *(int*)(dst + 0x148) = *(int*)(self + 0xb0);
    *(int*)(dst + 0x144) = *(int*)(self + 0xac);
    int* target = *(int**)(dst + 0x13c);
    if (target != 0) {
        *target = *(int*)(self + 0xb4);
    }
    *(int*)(dst + 0x134) = *(int*)(self + 0xb0) + 0x2c;
    if (GetIntAt0x6c(self) & 0x20000000) {
        SetBitsInField0x6c(dst, 0x20000000);
    }
    TargetObj02048588* p = *(TargetObj02048588**)(self + 0xb0);
    unsigned int bit = p->flag27;
    if (bit) {
        *(dst + 0xc2) &= ~0x10;
    } else {
        *(dst + 0xc2) |= 0x10;
    }
    void* q = *(void**)(self + 0xac);
    *(short*)(dst + 0x18e) = *(short*)((char*)q + 0x12);
}
