#include <globaldefs.h>

// USA: func_020120b8
ARM int* GetNegativeEntry(char* obj, int index) {
    int* arr = (int*)(obj + 0x5cdc);
    int* p = &arr[index];
    if (((unsigned int)*p >> 31) == 0) {
        p = 0;
    }
    return p;
}
