#include <globaldefs.h>

int EnqueueEvent0x6Sub6(int a, int b);
int SubmitCommandType1(int a);
extern "C" void func_020bc79c(void*);

struct Obj020bc6fc {
    char pad0[0x2c];
    unsigned char field2c;  /* 0x2c */
    char pad2d[0x3c - 0x2d];
    unsigned char field3c;  /* 0x3c */
};

// USA: func_020bc6fc
ARM void DispatchType2Command020bc6fc(struct Obj020bc6fc* obj) {
    if (obj->field2c == 2) {
        EnqueueEvent0x6Sub6(obj->field3c, 0xfffffd2d);
    }
    SubmitCommandType1(obj->field3c);
    func_020bc79c(obj);
}
