#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c7898(void*);

extern char data_021118e0;

// USA: func_020cff50
ARM int WaitForField0x114Bit4ClearIsNull(void) {
    char* base = &data_021118e0;
    unsigned int mask = DisableInterrupts();
    while (*(unsigned int*)(base + 0x114) & 4) {
        func_020c7898(base + 0x10c);
    }
    RestoreInterrupts(mask);
    return (**(int**)(base + 0x0) == 0) ? 1 : 0;
}
