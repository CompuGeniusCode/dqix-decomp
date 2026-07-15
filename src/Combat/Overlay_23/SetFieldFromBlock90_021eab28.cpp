#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Block90_021eab28 { unsigned short v0; unsigned char v2; };

// USA: func_ov023_021eab28
ARM int SetFieldFromBlock90_021eab28(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    struct Block90_021eab28* p = (struct Block90_021eab28*)(buf + 0x90);
    func_ov017_021d6134(obj, p->v0);
    func_ov017_021d6134((char*)obj + 0x8, p->v2);
    return 1;
}
