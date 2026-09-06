#include <globaldefs.h>

struct ListHeader021d99f8 {
    char pad4[4];
    void* arr;
    unsigned short size;
};

// USA: func_ov028_021d99f8
ARM void* GetElementIfInBounds_021d99f8(struct ListHeader021d99f8* list, unsigned int idx) {
    void* result = 0;
    if (idx < list->size) {
        result = (char*)list->arr + idx * 0xc;
    }
    return result;
}
