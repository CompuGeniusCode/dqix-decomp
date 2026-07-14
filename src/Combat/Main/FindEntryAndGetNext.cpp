#include <globaldefs.h>

char* FindNamedRecord0204673c(char* a, char* b);

// USA: func_020467c0
ARM char* FindEntryAndGetNext(void* a, char* b, void** outField44) {
    char* p = FindNamedRecord0204673c((char*)a, b);
    if (p == NULL) return NULL;
    if (outField44 != NULL) *outField44 = *(void**)(p + 0x44);
    return p + *(int*)(p + 0x40);
}
