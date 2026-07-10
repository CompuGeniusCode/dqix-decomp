#include <globaldefs.h>

extern "C" void func_020bc9a8(void *obj);

// USA: func_020bf2d4
ARM void ReleaseRefAt0x120(void *obj) {
    if (*(int *)((char *)obj + 0x120) == 0) return;
    if ((*(int *)((char *)obj + 0x120) -= 1) != 0) return;
    func_020bc9a8(obj);
}
