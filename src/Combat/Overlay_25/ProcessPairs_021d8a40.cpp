#include <globaldefs.h>

extern "C" void func_ov025_021d8ab8(void* obj0, void* obj1, int flag, int type, int idx);

struct S021d8a40 {
    char pad[8];
    unsigned char f8;
    unsigned char f9;
};

// USA: func_ov025_021d8a40
ARM void ProcessPairs_021d8a40(void* obj0, struct S021d8a40* obj1) {
    int lim[2];
    lim[0] = obj1->f9;
    lim[1] = obj1->f8;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < lim[j]; k++) {
            func_ov025_021d8ab8(obj0, obj1, 1, 6, j);
        }
    }
}
