#include <globaldefs.h>

struct Struct02082d38;
void CopyStruct02082d38(struct Struct02082d38* dst, struct Struct02082d38* src);

extern "C" void func_020891cc(void* dst, void* src1, void* src2);

struct Packed3c_0208936c {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int fieldD : 2;
};

// USA: func_0208936c
ARM void CopyCombatantStats0208936c(char* dst, char* src1, char* src2) {
    func_020891cc(dst, src1, src2);

    *(unsigned short*)(dst + 0x0) = *(unsigned short*)(src1 + 0x4);
    *(unsigned short*)(dst + 0x2) = *(unsigned short*)(src1 + 0x6);
    *(unsigned short*)(dst + 0x4) = *(unsigned short*)(src2 + 0x30);
    *(unsigned short*)(dst + 0x6) = *(unsigned short*)(src2 + 0x32);
    CopyStruct02082d38((struct Struct02082d38*)(dst + 0x3e), (struct Struct02082d38*)(src1 + 0x9));

    *(unsigned char*)(dst + 0x24) = *(unsigned char*)(src1 + 0x8);

    unsigned int flagsWord = *(unsigned int*)(src1 + 0x0);
    *(unsigned int*)(dst + 0x14) = flagsWord;
    if (flagsWord & 0x2) {
        unsigned short v = *(unsigned short*)(dst + 0x22);
        v = (v & ~3) | 1;
        *(unsigned short*)(dst + 0x22) = v;
    }

    unsigned char t = *(unsigned char*)(dst + 0x24);
    if (t != 0) {
        *(unsigned int*)(dst + 0x14) |= 0x800000;
        *(unsigned char*)(dst + 0x24) = t;
    }

    *(unsigned short*)(dst + 0xc) = *(unsigned short*)(src2 + 0x38);
    *(unsigned short*)(dst + 0x8) = *(unsigned short*)(src2 + 0x34);
    *(unsigned short*)(dst + 0xa) = *(unsigned short*)(src2 + 0x36);
    ((Packed3c_0208936c*)(dst + 0x10))->fieldA = (unsigned short)((Packed3c_0208936c*)(src2 + 0x3c))->fieldA;
    ((Packed3c_0208936c*)(dst + 0x10))->fieldB = (unsigned short)((Packed3c_0208936c*)(src2 + 0x3c))->fieldB;
    ((Packed3c_0208936c*)(dst + 0x10))->fieldC = (unsigned short)((Packed3c_0208936c*)(src2 + 0x3c))->fieldC;
    *(unsigned char*)(dst + 0x26) = 1;
}
