#include <globaldefs.h>

struct NameTable02048080;
struct Struct02047230;

void ClearNameTable(NameTable02048080* table);
void MaybeInvoke0204719c(Struct02047230* obj);

// USA: func_0201c108
ARM void* NotifyThenResetNameTable(void* obj) {
    MaybeInvoke0204719c((Struct02047230*)obj);
    ClearNameTable((NameTable02048080*)((char*)obj + 0x14));
    return obj;
}
