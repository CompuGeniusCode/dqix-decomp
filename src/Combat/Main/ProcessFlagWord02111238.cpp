#include <globaldefs.h>

extern "C" void func_020c490c(void* flags);

extern unsigned short data_02111238;

// USA: func_020c4ad4
ARM void ProcessFlagWord02111238(void) {
    func_020c490c(&data_02111238);
}
