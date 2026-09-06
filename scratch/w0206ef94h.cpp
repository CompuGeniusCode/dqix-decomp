#include <globaldefs.h>

// USA: func_0206ef94
ARM int GetFieldSumOrDefault_0206ef94(void* obj, int key, int fallback) {
    int result = fallback;
    int found = 0;
    if (key != -1) {
        if (*(int*)((char*)obj + 0x8) != 0) {
            found = 1;
        }
    }
    if (found) {
        result = *(int*)((char*)obj + 0x8) + key;
    }
    return result;
}
