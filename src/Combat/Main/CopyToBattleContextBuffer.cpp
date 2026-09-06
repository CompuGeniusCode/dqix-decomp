#include <globaldefs.h>

void* GetBattleContext(void);
int GetBattleStateCode(void);
void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" int func_020ca4b4(void*, void*, int);

struct BattleCtx020d4848 {
    unsigned char pad0[4];
    void* buffer;
};

// USA: func_020d4848
ARM int CopyToBattleContextBuffer(void* src) {
    struct BattleCtx020d4848* ctx = (struct BattleCtx020d4848*)GetBattleContext();
    int state = GetBattleStateCode();
    if (state != 0) {
        return state;
    }
    if (src == NULL) {
        return 6;
    }
    InvalidateDataCacheRange((const void*)((int)ctx->buffer), 0x7d0);
    func_020ca4b4(ctx->buffer, src, 0x7d0);
    return 0;
}
