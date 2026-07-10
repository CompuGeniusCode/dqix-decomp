#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short*);
extern unsigned short data_0211122c;

// USA: func_020c4a5c
ARM int ResetVramBanks0211122c() {
    return func_020c490c(&data_0211122c);
}
