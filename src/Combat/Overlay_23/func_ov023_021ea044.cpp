#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

struct ShortPair021ea044 { unsigned short lo, hi; };
extern "C" ShortPair021ea044 func_ov023_021e8fe8(ShortPair021ea044 v, int kind);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021ea044
extern "C" ARM int func_ov023_021ea044(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);

    ShortPair021ea044 result = func_ov023_021e8fe8(*(ShortPair021ea044*)(buf + 0x6c), 1);

    func_ov017_021d6134(obj, result.lo);
    func_ov017_021d6134((char*)obj + 8, *(unsigned char*)&result.hi);
    return 1;
}
