#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

extern int data_0210fcf4;
extern int data_0210fcb4;

struct Obj_020bcd30 {
    char pad0[0x20];
    int f20;
    char pad24[4];
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    char pad3c[0x48 - 0x3c];
    int f48;
    unsigned char f4c[1];
};

struct TableEntry_020bcd30 {
    int a;
    int b;
};

typedef int (*Callback_020bcd30)(void*, int, int*, unsigned int, int, int);

// USA: func_020bcd30  (semantic: RunDivTableCallback_020bcd30)
extern "C" ARM void func_020bcd30(Obj_020bcd30* obj, void* param2) {
    unsigned int divResult = _u32_div_f(obj->f28, obj->f2c);
    int mulVal = divResult * obj->f38;
    int i = 0;
    if (obj->f48 > 0) {
        do {
            unsigned char idx = obj->f4c[i];
            int word = ((TableEntry_020bcd30*)&data_0210fcf4)[idx].a;
            ((int*)&data_0210fcb4)[i] = word + mulVal;
            i++;
        } while (i < obj->f48);
    }
    Callback_020bcd30 cb = (Callback_020bcd30)obj->f30;
    cb(param2, obj->f48, (int*)&data_0210fcb4, divResult, obj->f20, obj->f34);

    int newCount = obj->f38 + 1;
    obj->f38 = newCount;
    if (newCount >= obj->f2c) {
        obj->f38 = 0;
    }
}
