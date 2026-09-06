#include <globaldefs.h>

extern "C" void func_020ca3ec(int value, void* dest, int count);

struct Struct020d5898 {
    int type;
    unsigned short valA;
    unsigned short valB;
    int zero1;
    int zero2;
};

extern "C" void func_020d5684(int, int, int, int, unsigned short, struct Struct020d5898*);

// USA: func_020d5898
ARM void BuildAndDispatch020d5898(int a, int b, int c, int d, unsigned short e, unsigned short f) {
    struct Struct020d5898 s;
    func_020ca3ec(0, &s, 0x10);
    s.type = 3;
    s.valA = f;
    s.valB = f;
    func_020d5684(a, b, c, d, e, &s);
}
