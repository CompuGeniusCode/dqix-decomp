#include <globaldefs.h>

struct S020d8fcc;
ARM int GetDataPtrAndValue020d8fcc(void** outPtr, unsigned int* outVal, unsigned char* base, struct S020d8fcc* s);
extern "C" void* func_020d901c(unsigned char* base, int idx);
extern int data_020f27c0;

// USA: func_020d9100
ARM int LookupAndFetchIfKeyMatches020d9100(void** outPtr, unsigned int* outVal, unsigned char* base, int idx) {
    *outPtr = 0;
    *outVal = 0;
    if (base == NULL) {
        goto ret0;
    }
    if (*(int*)base == *(int*)((char*)&data_020f27c0 + 0xc)) {
        goto work;
    }
ret0:
    return 0;
work: {
        struct S020d8fcc* s = (struct S020d8fcc*)func_020d901c(base, idx);
        return GetDataPtrAndValue020d8fcc(outPtr, outVal, base, s);
    }
}
