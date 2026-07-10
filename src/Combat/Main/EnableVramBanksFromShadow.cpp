#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);
extern unsigned short data_02111224;

// USA: func_020c47c8
ARM int EnableVramBanksFromShadow(unsigned short* entry) {
    unsigned short v = *entry;
    *entry = 0;
    data_02111224 |= v;
    func_020c3aac(v);
    return v;
}
