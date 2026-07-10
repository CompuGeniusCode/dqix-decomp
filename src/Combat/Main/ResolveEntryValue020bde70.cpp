#include <globaldefs.h>

extern "C" int* func_020bd4b8(int);
extern "C" int func_020be1a8(int, int, int);
int GetListEntryWord8020bd8ac(unsigned int);

// USA: func_020bde70
ARM int ResolveEntryValue020bde70(int id, int flags, int b, int c, int* out) {
    int* entry = func_020bd4b8(id);
    if (entry == NULL) return 3;
    int val = *entry;
    int result;
    if (flags & 8) {
        result = func_020be1a8(val, b, c);
        if (result == 0) return 7;
    } else {
        result = GetListEntryWord8020bd8ac(val);
    }
    if (out != NULL) *out = result;
    return 0;
}
