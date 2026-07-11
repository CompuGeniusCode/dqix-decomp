#include <globaldefs.h>

struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};
void ResetListHeader020727d8(struct List020727d8* list);

// USA: func_020727ec
ARM void ResetListHeader020727ec(struct List020727d8* list) {
    ResetListHeader020727d8(list);
}
