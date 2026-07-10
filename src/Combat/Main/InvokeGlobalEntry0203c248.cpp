#include <globaldefs.h>

extern char* data_02105244;
extern "C" void func_02042764(void* entry, int arg, int zero);

// USA: func_0203c248
ARM void InvokeGlobalEntry0203c248(char* obj, int arg1) {
    char* base = data_02105244;
    char* arr;
    short idx;
    if (base == NULL) return;
    arr = base + 4;
    idx = *(short*)(obj + 0x14);
    if (idx < 0) return;
    func_02042764(arr + idx * 0x28, arg1, 0);
}
