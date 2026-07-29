#include <globaldefs.h>

struct Table020429e4;

extern "C" Table020429e4* _Z18GetField0x10IfArg8i(int arg);
extern "C" void* _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(Table020429e4* table, unsigned char key);
extern "C" int _Z17GetGlobal02109400v();
extern "C" int _Z19AlwaysFalse02094b44v();

// USA: func_02042a50
ARM void* FindOrFallbackEntry_02042a50(int arg0, unsigned char key) {
    if (key == 0) return 0;
    void* result = _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(_Z18GetField0x10IfArg8i(arg0), key);
    if (result != 0) return result;
    _Z17GetGlobal02109400v();
    unsigned char secondKey = (unsigned char)arg0;
    int fallback = _Z19AlwaysFalse02094b44v();
    secondKey = key;
    return _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph((Table020429e4*)fallback, secondKey);
}
