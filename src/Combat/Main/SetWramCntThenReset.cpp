#include <globaldefs.h>

void SetWramCnt(unsigned char value);
extern "C" void func_020c9f2c(int arg);

// USA: func_020cad00
ARM void SetWramCntThenReset(void) {
    SetWramCnt(3);
    func_020c9f2c(0);
}
