#include <globaldefs.h>

extern char data_ov016_0219d0c0[];

// USA: func_ov016_0218be5c
ARM int GetSomeConstByFlag_0218be5c(void) {
    int flag = *(int*)(data_ov016_0219d0c0 + 0x18);
    if (flag == 0) {
        return 0x6820000;
    }
    return 0x6800000;
}
