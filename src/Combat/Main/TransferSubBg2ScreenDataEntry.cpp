#include <globaldefs.h>

extern int TransferSubBg2ScreenData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb80
ARM int TransferSubBg2ScreenDataEntry(int arg0, int arg1, unsigned int arg2) {
    return TransferSubBg2ScreenData(arg0, arg1, arg2);
}
