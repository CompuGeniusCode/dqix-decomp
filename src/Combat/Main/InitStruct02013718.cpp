#include <globaldefs.h>

extern "C" void func_020134e0(void* obj);

// USA: func_02013718
ARM void InitStruct02013718(char* obj, int a, int b) {
    func_020134e0(obj);
    *(int*)(obj + 0x4c) = a;
    *(int*)(obj + 0x50) = b;
    *(int*)(obj + 0x838) = 0;
    *(int*)(obj + 0x83c) = 0;
    *(short*)(obj + 0x474) = 0;
    *(int*)(obj + 0x82c) = 0;
}
