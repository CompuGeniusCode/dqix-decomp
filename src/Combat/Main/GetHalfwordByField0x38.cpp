#include <globaldefs.h>

struct HalfwordByField0x38 {
    char pad0[4];
    unsigned short arr[3];
    char pad1[0x2e];
    int count;
};

// USA: func_020a40c0
ARM int GetHalfwordByField0x38(struct HalfwordByField0x38* obj) {
    int n = obj->count;
    if (n >= 1 && n <= 3) {
        return obj->arr[n - 1];
    }
    return 0;
}
