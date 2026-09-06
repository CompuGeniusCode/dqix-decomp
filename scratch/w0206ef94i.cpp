#include <globaldefs.h>

// USA: func_0206ef94
ARM int GetFieldSumOrDefault_0206ef94(void* obj, int key, int fallback) {
    int result = fallback;
    int useFallback = 1;
    int k = key;
    if (k != -1) {
        if (*(int*)((char*)obj + 0x8) != 0) {
            useFallback = 0;
        }
    }
    if (!useFallback) {
        result = *(int*)((char*)obj + 0x8) + k;
    }
    return result;
}
