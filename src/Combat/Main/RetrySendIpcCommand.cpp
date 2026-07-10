#include <globaldefs.h>

extern "C" int func_020cae94(int, int, int);

// USA: func_020c98c4
ARM void RetrySendIpcCommand(int arg) {
    int packed = arg << 8;
    while (func_020cae94(0xc, packed, 0)) {
    }
}
