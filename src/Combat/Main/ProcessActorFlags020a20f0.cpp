#include <globaldefs.h>
int GetField0x218(struct S020a3570*);

extern "C" void func_020a212c(void* actor, int arg);

// USA: func_020a20f0
ARM void ProcessActorFlags020a20f0(void* actor) {
    unsigned char* a = (unsigned char*)actor;
    if (GetField0x218((struct S020a3570*)(actor))) {
        a[0x244] |= 8;
        return;
    }
    if (*(int*)(a + 0x238) == 0) {
        return;
    }
    func_020a212c(actor, 1);
}
