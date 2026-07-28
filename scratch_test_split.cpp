#include <globaldefs.h>

extern "C" int f1(char* p) {
    int* q = (int*)(p + 0x5d00);
    return *q;
}

struct BigStruct { char pad[0x5d00]; int field; };
extern "C" int f2(char* p) {
    struct BigStruct* s = (struct BigStruct*)p;
    return s->field;
}

extern "C" int f3(char* p) {
    return *(int*)(p + 0x5d00);
}
