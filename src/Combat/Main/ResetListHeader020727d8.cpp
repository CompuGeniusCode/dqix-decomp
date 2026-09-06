#include <globaldefs.h>

struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};

// USA: func_020727d8
ARM void ResetListHeader020727d8(struct List020727d8* list) {
    list->entries = 0;
    list->capacity = 0;
    list->count = 0;
}
