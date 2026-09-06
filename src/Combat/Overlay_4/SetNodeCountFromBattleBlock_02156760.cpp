#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int a);
int ScaleStatsIfType12_021f6f10(void* self);
int LoadBattleBlock020ac4c0(void* dst);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct BlockField02156760 {
    char pad[0x10];
    unsigned int val : 9;
};

struct Node02156760 {
    char pad[0x5c];
    unsigned short f5c;
    unsigned short f5e;
};

// USA: func_ov004_02156760  (semantic: SetNodeCountFromBattleBlock_02156760)
extern "C" ARM int func_ov004_02156760(void* a1) {
    char buf[0xb0];
    struct Node02156760* node = (struct Node02156760*)func_ov023_021f6880(func_ov011_021849c8(a1), 3);
    if (node == 0) {
        return 0;
    }
    if (ScaleStatsIfType12_021f6f10(node) != 7) {
        return 0;
    }
    LoadBattleBlock020ac4c0(buf);
    unsigned int q;
    unsigned int bits = ((struct BlockField02156760*)buf)->val;
    q = _u32_div_f(bits, 12);
    unsigned int r = bits % 12;
    if (r != 0) {
        q = q + 1;
    }
    if (q != 0) {
        node->f5c = 0;
        node->f5e = q;
        return 0;
    }
    func_ov011_021848a0(a1, 0x66);
    return 0;
}
