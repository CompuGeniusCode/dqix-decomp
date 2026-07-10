#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);
extern unsigned short data_02111224;

// USA: func_020c4590
ARM void EnableVramBanksByMask(unsigned short mask) {
    data_02111224 |= mask;
    func_020c3aac(mask);
}
