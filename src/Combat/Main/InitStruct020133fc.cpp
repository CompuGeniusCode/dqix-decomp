#include <globaldefs.h>

extern "C" void func_020130a8(void*, int, int, int);

// USA: func_020133fc
ARM void InitStruct020133fc(char* obj) {
    func_020130a8(obj, 0, 0, 0);
    *(short*)(obj + 0xc) = 0;
    *(short*)(obj + 0xe) = 0;
    *(short*)(obj + 0x10) = 0;
    *(char*)(obj + 0x16) = 1;
    *(char*)(obj + 0x17) = 0;
    *(short*)(obj + 0x1a) = -1;
    *(short*)(obj + 0x1c) = 0;
    *(char*)(obj + 0x14) = -1;
    *(int*)(obj + 0x20) = 0;
    *(char*)(obj + 0x19) = 0;
    *(short*)(obj + 0x12) = -1;
    *(char*)(obj + 0x18) = 0;
}
