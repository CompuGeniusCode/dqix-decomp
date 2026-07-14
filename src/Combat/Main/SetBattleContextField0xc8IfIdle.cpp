#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
int GetBattleStateCode(void);
unsigned int SetIRQInterruptState(int mask);
void* GetBattleContext(void);

// USA: func_020d472c
ARM int SetBattleContextField0xc8IfIdle(void* param) {
    unsigned int mask = DisableIRQInterrupts();
    int state = GetBattleStateCode();
    if (state != 0) {
        SetIRQInterruptState(mask);
        return state;
    }
    void* ctx = GetBattleContext();
    *(void**)((char*)ctx + 0xc8) = param;
    SetIRQInterruptState(mask);
    return 0;
}
