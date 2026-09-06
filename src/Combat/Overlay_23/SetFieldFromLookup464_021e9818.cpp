#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
extern "C" int func_ov017_021d60f4(void* variant);
extern "C" void func_ov017_021d6134(void* variant, int val);
extern "C" void* func_ov023_021e8f28(int idx);

// USA: func_ov023_021e9818
ARM int SetFieldFromLookup464_021e9818(void* a) {
    _Z15GetBattleStructv();
    int idx = func_ov017_021d60f4(a);
    void* e = func_ov023_021e8f28(idx);
    if (e == NULL) return 0;
    int idx2 = func_ov017_021d60f4((char*)a + 0x8);
    char* base = *(char**)((char*)e + 0x150);
    unsigned char v = *(unsigned char*)(base + (idx2 & 0xff) + 0x464);
    func_ov017_021d6134((char*)a + 0x10, v);
    return 1;
}
