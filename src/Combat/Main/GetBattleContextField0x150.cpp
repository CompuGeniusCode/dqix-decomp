#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);

extern char data_021142e0;

struct BattleContext020d46cc { unsigned char pad[0x150]; unsigned short field_0x150; };

// USA: func_020d46cc
ARM int GetBattleContextField0x150(void) {
    unsigned int mask = DisableInterrupts();
    struct BattleContext020d46cc* ctx = *(struct BattleContext020d46cc**)(&data_021142e0 + 4);
    int result = ctx ? ctx->field_0x150 : 0;
    RestoreInterrupts(mask);
    return result;
}
