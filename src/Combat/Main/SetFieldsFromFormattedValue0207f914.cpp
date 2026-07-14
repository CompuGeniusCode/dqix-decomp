#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0200f374(void* buf, int len);
int GetData02104304Field4();
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern char data_020f0fd0[];
extern char data_020f0fdc[];
extern char data_020f0fe7[];

struct Obj0207f914 {
    char pad0[0x14];
    int field0x14;
    char pad1[0x20 - 0x18];
    int field0x20;
    int field0x24;
    int field0x28;
};

// USA: func_0207f914
ARM void SetFieldsFromFormattedValue0207f914(struct Obj0207f914* obj, int p1, int p2, int p3) {
    if (p1 != 0 && p2 != 0 && p3 != 0) {
        obj->field0x14 = p1;
        int field4 = GetData02104304Field4();
        char bufA[0x20];
        func_0200f374(bufA, 0x20);
        char bufB[0x20];
        func_0200f374(bufB, 0x20);
        char bufC[0x20];
        func_0200f374(bufC, 0x20);
        sprintf(bufC, data_020f0fd0, p3);
        sprintf(bufB, data_020f0fdc, p3);
        sprintf(bufA, data_020f0fe7, p3);
        obj->field0x20 = CallFunc0202fa38Mode2(field4, p2, (int)bufC, 0);
        obj->field0x24 = CallFunc0202fa38Mode2(field4, p2, (int)bufB, 0);
        obj->field0x28 = CallFunc0202fa38Mode2(field4, p2, (int)bufA, 0);
    }
}
