#include <globaldefs.h>

extern "C" void func_020b6acc(int id, int* arr, int count);

struct Obj020b5f90 {
    int counter;         // 0x0
    char pad0[0x8 - 0x4];
    int flags8;          // 0x8
    char pad1[0xe0 - 0xc];
    int fieldE0;          // 0xe0
    int fieldE4;          // 0xe4
};

// USA: func_020b5f90
#pragma optimize_for_size off
ARM void IncrementCounterAndNotify020b5f90(struct Obj020b5f90* obj, int which) {
    if (!(obj->flags8 & 0x100) && !(obj->flags8 & 0x200)) {
        int arr[3];
        if (which == 0) {
            int v = obj->fieldE0;
            arr[2] = v;
            arr[1] = v;
            arr[0] = v;
        } else {
            int v = obj->fieldE4;
            arr[2] = v;
            arr[1] = v;
            arr[0] = v;
        }
        func_020b6acc(0x1b, arr, 3);
    }
    obj->counter += 1;
}
