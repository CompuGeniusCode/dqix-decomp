#include <globaldefs.h>

extern "C" void func_02093ad8(char* a, char* b, char* c, int d);

// USA: func_02093a98
ARM void MoveValue3ccTo3cb(char* obj) {
    func_02093ad8(obj, obj + 0x1a0, obj, obj[0x3cc]);
    obj[0x3cb] = obj[0x3cc];
    obj[0x3cc] = 0;
    ((unsigned char*)obj)[0x3cd] &= ~4;
}
