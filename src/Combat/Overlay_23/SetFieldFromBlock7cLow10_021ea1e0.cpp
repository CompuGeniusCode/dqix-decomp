#include <globaldefs.h>

struct S_ea1e0 {
    char pad[0x7c];
    unsigned int val : 10;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea1e0  (semantic: SetFieldFromBlock7cLow10_021ea1e0)
extern "C" ARM int func_ov023_021ea1e0(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_ea1e0*)buf)->val);
    return 1;
}
