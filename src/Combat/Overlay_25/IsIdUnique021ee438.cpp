#include <globaldefs.h>

struct Ctx021ee438 {
    char pad0[0xb0];
    int arr[(0x150 - 0xb0) / 4];
    unsigned char count;
    char pad1[7];
    int f158;
};

// USA: func_ov025_021ee438
ARM int IsIdUnique021ee438(struct Ctx021ee438* obj, int id) {
    if (id == 0) {
        return 1;
    }
    if (id == obj->f158) {
        return 0;
    }
    int i;
    for (i = 0; i < obj->count; i++) {
        int v = obj->arr[i];
        if (v == id) {
            return 0;
        }
    }
    return 1;
}
