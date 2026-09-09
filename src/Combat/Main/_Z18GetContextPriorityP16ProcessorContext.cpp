#include <globaldefs.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c7b38  (semantic: Synth_020c7b38)
extern "C" ARM int _Z18GetContextPriorityP16ProcessorContext(void* p) {
    return *(int*)((char*)p + 0x70);
}
