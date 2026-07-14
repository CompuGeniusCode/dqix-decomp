#include <globaldefs.h>

unsigned int DisableInterrupts(void);
int GetBattleStateCode(void);
unsigned int RestoreInterrupts(unsigned int mask);
void* GetBattleContext(void);

// USA: func_020d472c
ARM int SetBattleContextField0xc8IfIdle(void* param) {
    unsigned int mask = DisableInterrupts();
    int state = GetBattleStateCode();
    if (state != 0) {
        RestoreInterrupts(mask);
        return state;
    }
    void* ctx = GetBattleContext();
    *(void**)((char*)ctx + 0xc8) = param;
    RestoreInterrupts(mask);
    return 0;
}
