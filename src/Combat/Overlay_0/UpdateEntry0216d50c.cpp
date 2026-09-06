#include <globaldefs.h>

extern "C" void func_ov000_0216d560(void* work, int id);
extern "C" void func_0202e0a4(void* work);

// USA: func_ov000_0216d50c
ARM void UpdateEntry0216d50c(void* work) {
    int id = *(int*)((char*)work + 0x224);
    if (id >= 0) {
        func_ov000_0216d560(work, id);
    }
    func_0202e0a4(work);
}
