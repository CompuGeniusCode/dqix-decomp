#include <globaldefs.h>

struct Entry_0216f414 {
    short id;
    char pad[0x18 - 2];
};

struct Obj_0216f414 {
    char pad0[8];
    struct Entry_0216f414* arr;
    char pad1[0x14 - 0xc];
    unsigned short count;
};

// USA: func_ov003_0216f414
ARM void* FindEntryByShortId_0216f414(struct Obj_0216f414* obj, int key) {
    struct Entry_0216f414* arr = obj->arr;
    unsigned short count;
    unsigned short i;
    if (arr == NULL) {
        return 0;
    }
    count = obj->count;
    if (count == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        short id = arr[i].id;
        if (id == key) {
            return &arr[i];
        }
    }
    return 0;
}
