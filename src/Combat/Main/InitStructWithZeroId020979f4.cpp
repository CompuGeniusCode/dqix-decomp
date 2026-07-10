#include <globaldefs.h>

struct Obj020979c0 {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    unsigned char h;
    unsigned char id;
    unsigned char k;
};

void InitStruct020979c0(struct Obj020979c0* p, unsigned char id);

// USA: func_020979f4
ARM void InitStructWithZeroId020979f4(struct Obj020979c0* p) {
    InitStruct020979c0(p, 0);
}
