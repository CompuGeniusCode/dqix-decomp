#include <globaldefs.h>

// USA: func_0206ef94
ARM int GetFieldSumOrGarbage_0206ef94(void* obj, int key) {
    int result;
    if (key != -1 && *(int*)((char*)obj + 0x8) != 0) {
        result = *(int*)((char*)obj + 0x8) + key;
    }
    return result;
}
