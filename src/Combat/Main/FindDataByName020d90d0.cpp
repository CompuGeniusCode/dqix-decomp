#include <globaldefs.h>
int LookupAndFetchIfKeyMatches020d9100(void**, unsigned int*, unsigned char*, int);

extern "C" int func_01ff860c(const char*);

// USA: func_020d90d0
ARM int FindDataByName020d90d0(void** outPtr, unsigned int* outVal, void* table, const char* name) {
    return LookupAndFetchIfKeyMatches020d9100((void**)(outPtr), (unsigned int*)(outVal), (unsigned char*)(table), (int)(func_01ff860c(name)));
}
