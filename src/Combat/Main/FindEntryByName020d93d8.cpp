#include <globaldefs.h>
int RelayActionIfStateValid020d9400(struct Handle020d9400*, unsigned char*, int);

extern "C" int func_01ff860c(const char*);

// USA: func_020d93d8
ARM int FindEntryByName020d93d8(void* handle, unsigned char* slot, const char* name) {
    return RelayActionIfStateValid020d9400((struct Handle020d9400*)(handle), (unsigned char*)(slot), (int)(func_01ff860c(name)));
}
