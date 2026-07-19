#include <globaldefs.h>

int LoadBattleBlock020ac460(void* dst);

// USA: func_ov023_021ed6cc
ARM bool TestBattleBlockBit_021ed6cc(int idx) {
    unsigned int block[15];
    LoadBattleBlock020ac460(block);
    int q = idx / 32;
    int r = idx % 32;
    int flag = 0;
    if (block[q] & (1 << r)) flag = 1;
    return flag != 0;
}
