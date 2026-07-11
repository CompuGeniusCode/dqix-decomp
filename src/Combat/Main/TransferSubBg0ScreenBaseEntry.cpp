#include <globaldefs.h>

extern int TransferToSubBg0ScreenBase(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb68
ARM int TransferSubBg0ScreenBaseEntry(int arg0, int arg1, unsigned int arg2) {
    return TransferToSubBg0ScreenBase(arg0, arg1, arg2);
}
