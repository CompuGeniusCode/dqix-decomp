#include <globaldefs.h>

// USA: func_0206ef94
ARM int GetFieldSumOrDefault_0206ef94(void* obj, int idx, int fallback) {
    int result = fallback;
    int useFallback = 1;
    if (idx == -1 || *(int*)((char*)obj + 0x8) == 0) {
        useFallback = 1;
    } else {
        useFallback = 0;
    }
    if (!useFallback) result = *(int*)((char*)obj + 0x8) + idx;
    return result;
}
