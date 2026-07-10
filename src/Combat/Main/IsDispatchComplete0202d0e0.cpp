#include <globaldefs.h>

extern "C" int func_020d5490(int (*cb)(void));
extern "C" int func_0202d108(void);
void SetField0x48UnlessState9Or10(int arg);

// USA: func_0202d0e0
ARM int IsDispatchComplete0202d0e0(void) {
    int r = func_020d5490(func_0202d108);
    if (r == 2) {
        return 1;
    }
    SetField0x48UnlessState9Or10(r);
    return 0;
}
