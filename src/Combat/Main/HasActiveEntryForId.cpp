#include <globaldefs.h>

void* FindEntryByFlagByte(unsigned char* arr, int offset);

// USA: func_0207da30
ARM int HasActiveEntryForId(unsigned char* arr, int id, int offset) {
    unsigned char* p = (unsigned char*)FindEntryByFlagByte(arr, offset);
    if (p == NULL) return 0;
    if (*(unsigned short*)p != id) return 0;
    return *(signed char*)(p + offset + 8) != -1;
}
