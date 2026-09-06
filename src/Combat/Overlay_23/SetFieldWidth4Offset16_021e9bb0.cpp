#include <globaldefs.h>

struct S_9bb0 {
    char pad[0x18];
    unsigned int lo : 16;
    unsigned int val : 4;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9bb0  (semantic: SetFieldWidth4Offset16_021e9bb0)
extern "C" ARM int func_ov023_021e9bb0(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9bb0*)buf)->val);
    return 1;
}
