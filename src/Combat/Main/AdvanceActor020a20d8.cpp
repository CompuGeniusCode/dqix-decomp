#include <globaldefs.h>

extern "C" void func_020a2d14(void* actor);
void ProcessActorFlags020a20f0(void* actor);

// USA: func_020a20d8
ARM void AdvanceActor020a20d8(void* actor) {
    func_020a2d14(actor);
    ProcessActorFlags020a20f0(actor);
}
