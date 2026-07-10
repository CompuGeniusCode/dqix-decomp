#include <globaldefs.h>

extern unsigned int DisableInterrupts();
extern unsigned int RestoreInterrupts(unsigned int);
extern "C" void func_020c7898(void*);

struct Thread7854 {
    char pad[0x64];
    int state;   /* 0x64 */
};

// USA: func_020c7854
ARM void RestoreThreadUnlessState2(struct Thread7854* thread) {
    unsigned int saved = DisableInterrupts();
    if (thread->state != 2) {
        func_020c7898((char*)thread + 0x9c);
    }
    RestoreInterrupts(saved);
}
