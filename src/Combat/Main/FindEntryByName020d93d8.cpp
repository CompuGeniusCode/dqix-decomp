#include <globaldefs.h>

extern "C" int func_01ff860c(const char*);
extern "C" int func_020d9400(void*, unsigned char*, int);

// USA: func_020d93d8
ARM int FindEntryByName020d93d8(void* handle, unsigned char* slot, const char* name) {
    return func_020d9400(handle, slot, func_01ff860c(name));
}
