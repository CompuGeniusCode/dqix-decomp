#include <globaldefs.h>

struct Entry0201137c { int a; unsigned int b; };
extern "C" struct Entry0201137c* func_0209a594(void* p, int id);

// USA: func_0201137c
ARM int GetSlotBits0201137c(char* base, int id) {
    struct Entry0201137c* e;
    unsigned int result = 0;
    e = func_0209a594(base + 0x572c, id);
    if (e != NULL) {
        result = (e->b << 12) >> 24;
    }
    return result;
}
