#include <globaldefs.h>

int IsStateActive0216265c(void* objRaw);

// USA: func_ov017_021b8b94
ARM int GetField6acThenCall_021b8b94(void* obj) {
    void* p = *(void**)((char*)obj + 0x6ac);
    if (p == NULL) {
        return 0;
    }
    return IsStateActive0216265c(p);
}
