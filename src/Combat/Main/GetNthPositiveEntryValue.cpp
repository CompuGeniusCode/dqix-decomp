#include <globaldefs.h>

void* GetPointerAt0xbf0(void* base, unsigned int index);
signed short GetShortFromArray0xc10(unsigned char* base, unsigned int index);

// USA: func_0207c72c
ARM short GetNthPositiveEntryValue(void* base, unsigned int index, short target) {
    signed char* arr = (signed char*)GetPointerAt0xbf0(base, index);
    if (arr == NULL) return 0;
    short count = 0;
    short bound = GetShortFromArray0xc10((unsigned char*)base, index);
    unsigned int i;
    for (i = 0; i < bound; i++) {
        if (*arr > 0) {
            if (target == count) return *arr;
            count++;
        }
        arr++;
    }
    return 0;
}
