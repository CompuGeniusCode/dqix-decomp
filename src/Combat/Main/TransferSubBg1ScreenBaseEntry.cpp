#include <globaldefs.h>

extern int TransferToSubBg1ScreenBase(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb74
ARM int TransferSubBg1ScreenBaseEntry(int arg0, int arg1, unsigned int arg2) {
    return TransferToSubBg1ScreenBase(arg0, arg1, arg2);
}
