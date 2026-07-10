#include <globaldefs.h>

extern "C" void func_020bcd30(void* obj, int flag);

// USA: func_020bcd20
ARM void Call020bcd30WithFlag1(void* obj) {
    func_020bcd30(obj, 1);
}
