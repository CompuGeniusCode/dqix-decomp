#include <globaldefs.h>

struct IntField0x64_020377c4;
struct IntField0x68_020377b4;
struct Shorts5c_374e0;

void SetShorts0x5cTo0x60(struct Shorts5c_374e0* obj, short a, short b, short c);
void SetIntAt0x64(struct IntField0x64_020377c4*, int);
void SetIntAt0x68(struct IntField0x68_020377b4*, int);
int GetIntAt0x6c(unsigned char* obj);
void SetBitsInField0x6c(unsigned char* obj, unsigned int mask);
void* CallFunc0207ec8cOnField0x8(void* obj);

struct AcTarget020484f8 {
    char unk0[0x8];
    short at8;
    short unkA;
    short atc;
    short ate;
};

struct Input020484f8 {
    struct AcTarget020484f8* ac;
    unsigned int val4;
    unsigned int val8;
};

// USA: func_020484f8
ARM void InitObjectFields020484f8(unsigned char* self, struct Input020484f8* in) {
    *(unsigned int*)(self + 0xb0) = in->val4;
    *(struct AcTarget020484f8**)(self + 0xac) = in->ac;
    *(unsigned int*)(self + 0xb4) = in->val8;
    SetShorts0x5cTo0x60((struct Shorts5c_374e0*)self, 0x10a, 0x10a, 0x10a);
    SetIntAt0x64((struct IntField0x64_020377c4*)self, (*(struct AcTarget020484f8**)(self + 0xac))->atc << 2);
    SetIntAt0x68((struct IntField0x68_020377b4*)self, (*(struct AcTarget020484f8**)(self + 0xac))->ate);
    if ((*(struct AcTarget020484f8**)(self + 0xac))->at8 == 0x140) {
        SetBitsInField0x6c(self, 0x20000000);
    }
    if (GetIntAt0x6c(self) & 0x20000000) return;
    CallFunc0207ec8cOnField0x8(self);
}
