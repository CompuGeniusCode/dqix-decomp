#include <globaldefs.h>

struct NameTable02048080;

void ClearNameTable(NameTable02048080* table);
extern "C" void func_0204719c(void* obj);

// USA: func_0201c0e8
ARM void* ResetNameTableThenNotify(void* obj) {
    ClearNameTable((NameTable02048080*)((char*)obj + 0x14));
    func_0204719c(obj);
    return obj;
}
