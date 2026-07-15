#include <globaldefs.h>

struct S_eacd8 {
    char pad[0xa0];
    unsigned int val : 9;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eacd8
ARM int SetFieldWidth9Offset0_021eacd8(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_eacd8*)buf)->val);
    return 1;
}
