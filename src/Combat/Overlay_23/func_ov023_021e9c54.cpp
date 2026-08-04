#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

struct ShortPair021e9c54 { unsigned short lo, hi; };
extern "C" ShortPair021e9c54 func_ov023_021e8fe8(ShortPair021e9c54 v, int kind);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021e9c54
extern "C" ARM int func_ov023_021e9c54(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);

    ShortPair021e9c54 result = func_ov023_021e8fe8(*(ShortPair021e9c54*)(buf + 0x4), 1);

    func_ov017_021d6134(obj, result.lo);
    func_ov017_021d6134((char*)obj + 8, *(unsigned char*)&result.hi);
    return 1;
}
