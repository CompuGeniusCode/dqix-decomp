#include <globaldefs.h>

extern "C" void func_020287b4(void* obj);
extern "C" void func_0200ef44(void* obj, int count, int size, void* initFn);
extern "C" void func_02028cfc(void);

// USA: func_02028d2c
ARM void* InitObjectArray02028d2c(void* obj) {
    func_020287b4(obj);
    func_0200ef44(obj, 4, 0x318, (void*)func_02028cfc);
    return obj;
}
