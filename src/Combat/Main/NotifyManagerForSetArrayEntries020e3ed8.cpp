#include <globaldefs.h>

extern "C" void func_020301c8(int, int);
int GetData02104304Field4(void);

struct Struct020e3ed8 {
    char pad[0x14];
    int arr[2];
};

// USA: func_020e3ed8
ARM void NotifyManagerForSetArrayEntries020e3ed8(struct Struct020e3ed8* p) {
    int x = GetData02104304Field4();
    int i;
    for (i = 0; i < 2; i++) {
        if (p->arr[i] != -1) {
            func_020301c8(x, p->arr[i]);
        }
    }
}
