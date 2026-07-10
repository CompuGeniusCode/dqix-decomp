#include <globaldefs.h>

extern "C" void func_02093ad8(char* a, char* b, char* c, int d);

// USA: func_02093a58
ARM void MoveValue3cbTo3cc(char* obj) {
    func_02093ad8(obj, obj, obj + 0x1a0, obj[0x3cb]);
    obj[0x3cc] = obj[0x3cb];
    obj[0x3cb] = 0;
    ((unsigned char*)obj)[0x3cd] &= ~4;
}
