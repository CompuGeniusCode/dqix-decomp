#include <globaldefs.h>

// USA: func_ov002_02157424  (semantic: FillFixedArrayFieldC54_02157424)
extern "C" ARM void func_ov002_02157424(void* obj, int* arr) {
    if (arr == NULL) return;
    for (int j = 0; j < 7; j++) arr[j] = -1;
    arr[0] = 4;
    int i = 0;
    while (i < *(int*)((char*)obj + 0x1000 + 0xc50)) {
        int v = *(int*)((char*)obj + i * 4 + 0x1000 + 0xc54);
        i++;
        arr[i] = v;
    }
}
