#include <globaldefs.h>

// USA: func_ov002_02157480  (semantic: FillFixedArrayField6e_02157480)
extern "C" ARM void func_ov002_02157480(void* obj, int* arr) {
    if (arr == NULL) return;
    for (int j = 0; j < 4; j++) arr[j] = -1;
    int i = 0;
    while (i < *((signed char*)obj + 0x1c00 + 0x73)) {
        arr[i] = *((signed char*)obj + i + 0x1c00 + 0x6e);
        i++;
    }
}
