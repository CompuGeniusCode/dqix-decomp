#include <globaldefs.h>

struct S_9974 {
    char pad[0x10];
    unsigned int val : 9;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9974
ARM int SetFieldWidth9Offset0_021e9974(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9974*)buf)->val);
    return 1;
}
