#include <globaldefs.h>

extern "C" int func_01ff860c(const char*);
extern "C" int func_020d9580(void*, unsigned char*, int, void*, void*, int);

// USA: func_020d9538
ARM int FindEntryByNameEx020d9538(void* handle, unsigned char* slot, int a2, void* a3, void* a4, const char* name) {
    return func_020d9580(handle, slot, a2, a3, a4, func_01ff860c(name));
}
