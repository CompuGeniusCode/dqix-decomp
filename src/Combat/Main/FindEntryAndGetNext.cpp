#include <globaldefs.h>

extern "C" char* func_0204673c(void* a, char* b);

// USA: func_020467c0
ARM char* FindEntryAndGetNext(void* a, char* b, void** outField44) {
    char* p = func_0204673c(a, b);
    if (p == NULL) return NULL;
    if (outField44 != NULL) *outField44 = *(void**)(p + 0x44);
    return p + *(int*)(p + 0x40);
}
