#include <globaldefs.h>
#include "std_library_functions.h"

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

void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" ARM void* __clear(void* dst, int count);
extern char data_020ef6b6;
extern "C" int func_0205b234(void* selector, int weight, int mode, char* buf, int a, int b);

// USA: func_02023218  (semantic: FormatAndDispatchWeightedEntries_02023218)
extern "C" ARM void func_02023218(char* obj, int p1, int p2) {
    short a[21];
    short b[21];
    short c[21];
    short d[21];
    struct Struct02020520 arr[21];
    struct S_b20c sel;
    char buf[0x100];
    int i;
    int weight;
    int v;

    __clear(b, 0x2a);
    for (i = 0; i < 0x15; i++) {
        a[i] = i * 8;
        c[i] = 8;
        d[i] = 0x10;
    }
    InitWeightedEntries02023064(arr, 0x15, a, b, c, d);

    v = *(int*)(obj + 0xbe4);
    if (v > 0x98) {
        weight = -*(int*)(obj + 0xbe8);
    } else {
        weight = (0x98 - v) >> 1;
    }

    ClearTwoWordsAndByte(&sel);
    SetField0_0205b220(&sel, p1 + p2);
    SetFieldsAt0x4And0x8_0205b228(&sel, (int)arr, 0x15);

    __clear(buf, 0x100);
    sprintf(buf, &data_020ef6b6, obj + 0x5b4, obj + 0x5f4);

    func_0205b234(&sel, (short)weight, 3, buf, 0xf, 0);
}
