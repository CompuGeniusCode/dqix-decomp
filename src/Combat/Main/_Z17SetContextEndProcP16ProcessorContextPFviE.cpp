#include <globaldefs.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c7ca8  (semantic: Synth_020c7ca8)
extern "C" ARM void _Z17SetContextEndProcP16ProcessorContextPFviE(void* p, int v) {
    *(int*)((char*)p + 0xb4) = v;
}
