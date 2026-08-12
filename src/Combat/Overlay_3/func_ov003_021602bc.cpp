#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);

struct FmtTable021602bc { char rows[4][0x30]; };

// USA: func_ov003_021602bc
extern "C" ARM void func_ov003_021602bc(char* obj) {
    char* langData = (char*)func_ov017_0218b5b0();

    for (int i = 0; i < 4; i++) {
        (*(void***)(obj + 0x394))[i] = 0;
        void* buf = _ZN13SafeAllocator8AllocateEj(obj + 0x228, 0x30);
        (*(void***)(obj + 0x394))[i] = buf;
        void* p = (*(void***)(obj + 0x394))[i];
        memset(p, 0, 0x30);

        FmtTable021602bc* table = (FmtTable021602bc*)(langData + 0x435c);
        char* fmt = table->rows[i];
        if (fmt != 0) {
            void* dst = (*(void***)(obj + 0x394))[i];
            sprintf((char*)dst, fmt);
        }
    }
}
