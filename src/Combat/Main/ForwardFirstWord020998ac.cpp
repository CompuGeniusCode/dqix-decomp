#include <globaldefs.h>

extern int data_02114e20;
extern "C" int func_02012da4(void* obj, int value);

// USA: func_020998ac
ARM int ForwardFirstWord020998ac(int* p) {
    return func_02012da4(&data_02114e20, *p);
}
