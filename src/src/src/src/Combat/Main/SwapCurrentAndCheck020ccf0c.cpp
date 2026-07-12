#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" int func_020cc580(void* p);
extern "C" void func_020cc61c(void* p);

struct Ctx0211173c { unsigned char pad[4]; void* current; };
extern Ctx0211173c data_0211173c;
extern unsigned char data_02111754;

// USA: func_020ccf0c
ARM void* SwapCurrentAndCheck020ccf0c(void* obj) {
    unsigned int mask = DisableInterrupts();
    void* old = data_0211173c.current;
    int result = func_020cc580(&data_02111754);
    data_0211173c.current = obj;
    if (result) {
        func_020cc61c(&data_02111754);
    }
    RestoreInterrupts(mask);
    return old;
}
