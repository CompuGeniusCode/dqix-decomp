#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void* func_020cbc6c(void* obj);
extern "C" void func_020cbe80(void* p);

struct Stream020cc61c {
    unsigned char pad[0x1c];
    unsigned int flags;   // 0x1c
};

// USA: func_020cc61c
ARM int CloseStreamIfActive020cc61c(struct Stream020cc61c* obj) {
    void* res = NULL;
    unsigned int mask = DisableInterrupts();
    int flagSet = (obj->flags & 8) != 0;
    int result = !flagSet;
    if (!result) {
        obj->flags &= ~8;
        res = func_020cbc6c(obj);
    }
    RestoreInterrupts(mask);
    if (res != NULL) {
        func_020cbe80(res);
    }
    return result;
}
