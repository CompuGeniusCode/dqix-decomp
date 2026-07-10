#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short*);
extern unsigned short data_02111226;

// USA: func_020c49ec
ARM int ResetVramBanks02111226() {
    return func_020c490c(&data_02111226);
}
