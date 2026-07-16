#include <globaldefs.h>
void Callee(unsigned char* obj, unsigned char value);
extern "C" void func_x(void* a, int b, int c);
extern unsigned char flagbyte;

ARM void Test(void* p, int v) {
    if (flagbyte == 0) {
        func_x(p, v, 1);
    } else {
        Callee((unsigned char*)p, v);
    }
}
