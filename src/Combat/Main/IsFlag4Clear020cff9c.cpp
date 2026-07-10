#include <globaldefs.h>

extern char data_021118e0;

// USA: func_020cff9c
ARM int IsFlag4Clear020cff9c(void) {
    return (*(int*)(&data_021118e0 + 0x114) & 4) == 0 ? 1 : 0;
}
