#include <globaldefs.h>
extern "C" void Callee();
extern "C" void func_x(void* a, int b, int c);
extern unsigned char flagbyte;

ARM void Test(void* p, short v) {
    if (flagbyte == 0) {
        func_x(p, v, 1);
    } else {
        Callee(p, v);
    }
}
