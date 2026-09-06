#include <globaldefs.h>

void SetWramCnt(unsigned char value);
void ResetDMAChannel(int arg);

// USA: func_020cad00
ARM void SetWramCntThenReset(void) {
    SetWramCnt(3);
    ResetDMAChannel(0);
}
