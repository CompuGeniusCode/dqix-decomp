#include <globaldefs.h>

extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);

extern "C" void _Z29AccumulateFixedAngle_021d8a74P14Accum_021d8a74f(void* obj, unsigned int angle);
extern "C" void _Z24FillCombatBuffer021d8ad4PvPc(void* obj, char* buf);

struct ElemFld4_021d9208 {
    unsigned int nibble0 : 4;
    unsigned int twoBit : 2;
    unsigned int gap : 1;
    unsigned int field3 : 4;
    unsigned int rest : 21;
};

struct Elem_021d9208 {
    short a;
    short b;
    ElemFld4_021d9208 c;
    unsigned int d;
};

extern "C" struct Elem_021d9208* _Z29GetElementIfInBounds_021d99f8P18ListHeader021d99f8j(void* list, unsigned int idx);
extern "C" void func_ov028_021d8a40(void* buf, unsigned int val);
extern "C" int func_020420e8(void* d, int flag);
extern "C" void func_0204f41c(void* buf, int scaled, int byteField, void* d, unsigned char nibble0, unsigned char field3, short* p1, short* p2, int flagC);
extern "C" int _Z12TestFlagMaskPti(void* flagAddr, int mask);

extern int data_02114e30;

// USA: func_ov028_021d9208  (semantic: ApplyElementListEffects_021d9208)  (semantic: ApplyElementListEffects_021d9208)
extern "C" ARM void func_ov028_021d9208(char* self, int arg1) {
    unsigned int scale = *(unsigned int*)self;
    unsigned int argF = _fflt(arg1);
    unsigned int prod = _fmul(argF, scale);
    unsigned int angle = _fmul(0x3f000000u, prod);
    _Z29AccumulateFixedAngle_021d8a74P14Accum_021d8a74f(self + 0x60, angle);
    _Z24FillCombatBuffer021d8ad4PvPc(self + 0x60, *(char**)(self + 0x40));

    char* buf40 = *(char**)(self + 0x40);
    short prevIndex = -1;
    int scaled;
    int flagC;
    int byteField;
    short local2;
    short local1;
    unsigned int localBuf[0x38];
    int found;

    for (;;) {
        unsigned short idx = *(unsigned short*)(self + 0x6c);
        struct Elem_021d9208* elem = _Z29GetElementIfInBounds_021d99f8P18ListHeader021d99f8j(self, idx);
        if (elem == 0) {
            found = 1;
            goto exitLoop;
        }

        short elemIdx = elem->a;
        if (prevIndex != elemIdx) {
            unsigned int lhs = (*(int*)(self + 0x60) >> 12) + 0xc0;
            short elemB = elem->b;
            unsigned int rhs = elemB + (*(int*)(self + 0x64) >> 12);
            if (lhs < rhs) {
                goto fail;
            }
            *(unsigned int*)(self + 0x64) += (elemB << 12);
        }

        byteField = (*(int*)(self + 0x64) >> 12) & 0xff;
        flagC = 0;
        if (elem->c.nibble0 == 0xc) {
            flagC = 1;
        }
        scaled = 0;
        if (elem->c.twoBit != 0) {
            int base = func_020420e8((void*)elem->d, flagC);
            scaled = 0x88;
            switch (elem->c.twoBit) {
                case 1:
                    scaled = (0x100 - base) << 0xf >> 0x10;
                    break;
                case 2:
                    scaled = (short)(0x78 - base);
                    break;
            }
        }

        func_ov028_021d8a40(localBuf, (unsigned int)buf40);

        short nib = elem->c.nibble0;
        *(short*)((char*)localBuf + 0xb4) = nib;
        *(short*)((char*)localBuf + 0xb6) = nib + 1;

        func_0204f41c(localBuf, scaled, byteField, (void*)elem->d, elem->c.nibble0, elem->c.field3, &local1, &local2, flagC);

        if ((unsigned int)byteField + elem->c.nibble0 > 0x100) {
            func_0204f41c(localBuf, scaled, (short)(byteField - 0x100), (void*)elem->d, elem->c.nibble0, elem->c.field3, &local1, &local2, flagC);
        }

        *(unsigned short*)(self + 0x6c) = *(unsigned short*)(self + 0x6c) + 1;
        *(unsigned char*)(self + 0x6e) = 1;
        prevIndex = elem->a;
    }
fail:
    found = 0;
exitLoop:
    _Z12TestFlagMaskPti(&data_02114e30, 0x2000);
    if (found != 0) {
        *(unsigned char*)(self + 0x80) = 2;
        *(unsigned char*)(self + 0x81) = 0;
    }
}
