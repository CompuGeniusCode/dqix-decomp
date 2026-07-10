#include <globaldefs.h>

extern char data_021112ec;

// USA: func_020c75a4
ARM int GetGlobalWord021112ec(void) {
    return *(int*)(&data_021112ec);
}
