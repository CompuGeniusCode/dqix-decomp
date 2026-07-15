#include <globaldefs.h>
#include "Grotto/Overlay_17/Struct44C8.h"

struct ListHead02046b60;
extern "C" void func_02046a8c(struct ListHead02046b60* list, int val);

// USA: func_ov017_02197528
ARM void CallListIfFlagsSet_02197528(void) {
    char *base = (char*)func_ov017_0218b5b0() + 0x3000;
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + 0x6fc);
    unsigned char* flags = *(unsigned char**)(base + 0x734);
    if (flags[2] == 0) return;
    if (flags[3] != 0) return;
    func_02046a8c(list, (int)flags);
}
