#include <globaldefs.h>

struct StoreStruct {
    char pad[0x8b0];
    int arr[0x10];
};

// USA: func_020465c0
ARM void StoreInArray0x8b0(struct StoreStruct* base, int index, int value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        base->arr[index] = value;
    }
}
