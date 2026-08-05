#include <globaldefs.h>

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

extern "C" void func_02012fe4(void);
extern "C" void* func_0200f374(void* dst, int count);
void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" int func_0205b234(void* selector, short weight, int mode, char* buf, int a, int b);

// USA: func_020230fc  (semantic: FormatAndDispatchWeightedEntries_020230fc)
extern "C" ARM void func_020230fc(char* obj, int p1, int p2) {
    short a[18];
    short b[18];
    short c[18];
    short d[18];
    struct Struct02020520 arr[18];
    struct S_b20c sel;
    int i;
    int weight;
    int v;
    int roundedV;

    func_02012fe4();
    func_0200f374(b, 0x24);
    for (i = 0; i < 0x12; i++) {
        a[i] = i * 8;
        c[i] = 8;
        d[i] = 0x10;
    }

    obj[0x5a8] = 0;
    if (obj[0xba2] != 0) {
        obj[0x5a8] = 1;
        InitWeightedEntries02023064(arr, 0x12, a, b, c, d);

        v = *(int*)(obj + 0xbe4);
        roundedV = (v + 7) & ~7;
        if (v > 0x90) {
            weight = -*(int*)(obj + 0xbe8);
        } else {
            weight = (roundedV - v) >> 1;
        }

        ClearTwoWordsAndByte(&sel);
        SetField0_0205b220(&sel, p1 + p2);
        SetFieldsAt0x4And0x8_0205b228(&sel, (int)arr, 0x12);

        func_0205b234(&sel, (short)weight, 3, obj + 0xba2, 0xf, 0);
    }
}
