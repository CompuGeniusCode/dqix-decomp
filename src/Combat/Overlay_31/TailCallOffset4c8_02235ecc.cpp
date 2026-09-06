#include <globaldefs.h>

extern char* data_ov031_02290cfc;
extern "C" void func_ov031_022366d8(void*, char*);

// USA: func_ov031_02235ecc
ARM void TailCallOffset4c8_02235ecc(void* a) {
    func_ov031_022366d8(a, data_ov031_02290cfc + 0x4c8);
}
