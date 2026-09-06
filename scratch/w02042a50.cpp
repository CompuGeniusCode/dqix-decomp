#include <globaldefs.h>

extern "C" void* _Z18GetField0x10IfArg8i(int arg);
extern "C" void* _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(void* table, unsigned char key);
extern "C" void* _Z17GetGlobal02109400v(void);
extern "C" int _Z19AlwaysFalse02094b44v(void);

// USA: func_02042a50
ARM void* Func02042a50(int p1, unsigned char p2) {
    if (p2 == 0) return 0;
    void* table = _Z18GetField0x10IfArg8i(p1);
    void* result = _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(table, p2);
    if (result != 0) return result;
    _Z17GetGlobal02109400v();
    return _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph((void*)(int)_Z19AlwaysFalse02094b44v(), p2);
}
