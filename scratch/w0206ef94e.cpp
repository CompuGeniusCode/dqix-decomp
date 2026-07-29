#include <globaldefs.h>

// USA: func_0206ef94
ARM int GetFieldSumOrDefault_0206ef94(void* obj, int key, int fallback) {
    int useFallback = 1;
    int result = fallback;
    if (key != -1) {
        if (*(int*)((char*)obj + 0x8) != 0) {
            useFallback = 0;
        }
    }
    if (!useFallback) {
        result = key + *(int*)((char*)obj + 0x8);
    }
    return result;
}
