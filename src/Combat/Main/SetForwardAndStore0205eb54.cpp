#include <globaldefs.h>

void Forward0203aa80(void* obj, int arg2);
extern "C" void func_0203aa98(void*, int);

// USA: func_0205eb54
ARM void SetForwardAndStore0205eb54(void* obj, int arg1, int arg2) {
    Forward0203aa80(obj, *(int*)((char*)obj + 0xc0));
    func_0203aa98(obj, arg1);
    *(short*)((char*)obj + 0xc4) = (short)arg2;
}
