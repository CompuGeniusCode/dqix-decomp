#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_021d6134(void*, short);

// USA: func_ov023_021ea978
ARM int SetRoundedDown100_021ea978(void* obj) {
    short v = *(short*)func_02012fe4();
    func_ov017_021d6134(obj, (short)(v - v % 100));
    return 1;
}
