#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

struct Bitfield24_021ea344 { unsigned int v : 24; };

// USA: func_ov023_021ea344  (semantic: SetFieldFromBlock88_021ea344)
extern "C" ARM int func_ov023_021ea344(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    struct Bitfield24_021ea344* bf = (struct Bitfield24_021ea344*)(buf + 0x88);
    func_ov017_021d6134(obj, bf->v);
    return 1;
}
