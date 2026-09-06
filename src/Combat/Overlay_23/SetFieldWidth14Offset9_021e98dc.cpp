#include <globaldefs.h>

struct S_98dc {
    char pad[0x10];
    unsigned int lo : 9;
    unsigned int val : 14;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e98dc
ARM int SetFieldWidth14Offset9_021e98dc(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_98dc*)buf)->val);
    return 1;
}
