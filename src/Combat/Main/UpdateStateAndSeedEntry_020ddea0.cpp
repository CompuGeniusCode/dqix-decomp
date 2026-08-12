#include <globaldefs.h>

struct Struct_020de0ec;
void RollFlags020de0ec(struct Struct_020de0ec* obj);

struct StateObj020ddfb4;
void UpdateByStateByte020ddfb4(struct StateObj020ddfb4* obj);

int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be4c(void* obj);
extern "C" void* func_0203be40(void* obj);

struct Struct_020ddea0 {
    unsigned short field0;
    unsigned short field2;
    unsigned char state;
    unsigned char pad5[3];
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};

struct Elem8_020ddea0 {
    unsigned int word0;
    unsigned short half4;
    short half6;
};

// USA: func_020ddea0  (semantic: UpdateStateAndSeedEntry_020ddea0)
extern "C" ARM void func_020ddea0(Struct_020ddea0* obj, unsigned short threshold, unsigned int idx, unsigned int packVal, unsigned char flag1, unsigned char flag2) {
    if (obj->state == 0) {
        if (obj->field2 <= threshold) return;
        if (threshold < obj->field0) return;
        obj->state = 2;
        RollFlags020de0ec((struct Struct_020de0ec*)obj);
        return;
    }

    if (threshold >= obj->field2) {
        obj->state = 4;
    }
    UpdateByStateByte020ddfb4((struct StateObj020ddfb4*)obj);

    void* p1 = func_0203bd08();
    Elem8_020ddea0* arr = (Elem8_020ddea0*)func_0203be4c(p1);
    if (flag1 == 0) {
        arr = (Elem8_020ddea0*)func_0203be40(p1);
    }

    unsigned int bVal = obj->field8 + obj->field10;
    int aVal = obj->fieldc + obj->field14;
    int denom = obj->field18;
    if (obj->field18 <= 1) {
        denom = 0xa;
        aVal = 0xc0;
        bVal = 0x100;
    }

    int divResult = HwDivideRounded020c2bf4(0x1000, denom);

    arr[idx].word0 = (aVal & 0xff) | ((idx >> 2) << 0x19) | 0x40000000 | ((bVal << 0x17) >> 7) | 0x300;
    arr[idx].half4 = packVal | (flag2 << 0xc);
    Elem8_020ddea0* e = (Elem8_020ddea0*)((char*)arr + idx * 8);
    e->half4 &= ~0xc00;
    e->half6 = (short)(divResult >> 4);
    *(unsigned short*)((char*)e + 0xe) = 0;
    *(unsigned short*)((char*)e + 0x16) = 0;
    *(short*)((char*)e + 0x1e) = (short)(divResult >> 4);
}
