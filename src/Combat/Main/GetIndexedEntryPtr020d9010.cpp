#include <globaldefs.h>

// USA: func_020d9010
ARM int* GetIndexedEntryPtr020d9010(int* base) {
    unsigned short idx = *(unsigned short*)((char*)base + 6);
    return base + idx;
}
