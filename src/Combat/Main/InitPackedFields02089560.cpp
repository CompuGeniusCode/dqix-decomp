#include <globaldefs.h>

struct Struct02082d38;
void CopyStruct02082d38(struct Struct02082d38* dst, struct Struct02082d38* src);

struct Packed3c_89560 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int fieldD : 2;
};

// USA: func_02089560
ARM void InitPackedFields02089560(char* dst, char* buf, char* src) {
    *(dst + 0x25) = 0;
    *(dst + 0x38) = 0;
    CopyStruct02082d38((struct Struct02082d38*)(dst + 0x3e), (struct Struct02082d38*)(buf + 0x9));
    *(unsigned short*)(dst + 0xc) = *(unsigned short*)(src + 0x38);
    *(unsigned short*)(dst + 0x8) = *(unsigned short*)(src + 0x34);
    *(unsigned short*)(dst + 0xa) = *(unsigned short*)(src + 0x36);
    ((Packed3c_89560*)(dst + 0x10))->fieldA = (unsigned short)((Packed3c_89560*)(src + 0x3c))->fieldA;
    ((Packed3c_89560*)(dst + 0x10))->fieldB = (unsigned short)((Packed3c_89560*)(src + 0x3c))->fieldB;
    ((Packed3c_89560*)(dst + 0x10))->fieldC = (unsigned short)((Packed3c_89560*)(src + 0x3c))->fieldC;
    *(dst + 0x26) = 1;
}
