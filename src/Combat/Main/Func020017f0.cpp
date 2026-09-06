#include <globaldefs.h>

extern "C" void func_020017bc(int a, int* b);
extern "C" void func_020017c0(void* obj);

struct FlagsBits020017f0 {
    unsigned int lowBits : 12;
    unsigned int bit12 : 1;
};

struct S020017f0 {
    int f0;
    int flags;
    char pad1[0x10];
    int f18;
    int f1c;
    char pad2[0x4];
    int f24;
    int f28;
    char pad3[0x14];
    void* f40;
    char pad4[0x4];
    int f48;
};

typedef int (*FnPtr020017f0)(int, int, int*, int);

// USA: func_020017f0  (semantic: Func020017f0)
extern "C" ARM int func_020017f0(S020017f0* obj, int* outParam) {
    int delta = obj->f24 - obj->f1c;
    if (delta != 0) {
        obj->f28 = delta;
        if (!((FlagsBits020017f0*)&obj->flags)->bit12) {
            func_020017bc(obj->f1c, &obj->f28);
        }
        FnPtr020017f0 fn = (FnPtr020017f0)obj->f40;
        int result = fn(obj->f0, obj->f1c, &obj->f28, obj->f48);
        if (outParam != 0) *outParam = obj->f28;
        if (result != 0) return result;
        obj->f18 += obj->f28;
    }
    func_020017c0(obj);
    return 0;
}
