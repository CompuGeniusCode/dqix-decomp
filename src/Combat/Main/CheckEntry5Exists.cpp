#include <globaldefs.h>

extern "C" int func_020cae94(int, int, int);

// USA: func_020cf8bc
ARM int CheckEntry5Exists(int arg) {
    return func_020cae94(5, (arg << 8) & 0x7f00, 0) >= 0 ? 1 : 0;
}
