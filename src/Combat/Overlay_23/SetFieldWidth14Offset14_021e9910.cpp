#include <globaldefs.h>

struct S_9910 {
    char pad[0xc];
    unsigned int lo : 14;
    unsigned int val : 14;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9910
ARM int SetFieldWidth14Offset14_021e9910(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9910*)buf)->val);
    return 1;
}
