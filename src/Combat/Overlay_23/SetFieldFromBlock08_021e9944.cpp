#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9944
ARM int SetFieldFromBlock08_021e9944(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = *(unsigned int*)(buf + 0x8);
    func_ov017_021d6134(obj, v >> 0x18);
    return 1;
}
