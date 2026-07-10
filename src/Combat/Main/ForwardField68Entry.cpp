#include <globaldefs.h>

extern "C" int func_02075608(int, int, int*);
void SwapArgsAndCall0201e2b4(int, int, int, int);

// USA: func_020143d8
ARM int ForwardField68Entry(char* obj, int arg1) {
    int f68 = *(int*)(obj + 0x68);
    int out;
    int r = func_02075608(f68, arg1, &out);
    int saved = *(int*)(obj + 0x8);
    SwapArgsAndCall0201e2b4((int)(obj + 0x6c), f68, r, out);
    *(int*)(obj + 0x8) = saved;
    return 1;
}
