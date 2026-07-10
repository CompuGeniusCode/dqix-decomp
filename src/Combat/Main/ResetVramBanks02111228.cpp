#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short*);
extern unsigned short data_02111228;

// USA: func_020c4a00
ARM int ResetVramBanks02111228() {
    return func_020c490c(&data_02111228);
}
