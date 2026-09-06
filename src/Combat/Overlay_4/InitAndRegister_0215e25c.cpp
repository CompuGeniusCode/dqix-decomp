#include <globaldefs.h>
#include "std_library_functions.h"

struct Template0215e25c { unsigned int words[100]; };
extern Template0215e25c data_ov004_0216fc40;

extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);
extern "C" void func_ov011_02184a24(void* obj, void* data, int size);
extern "C" void func_ov011_02184c28(void* obj, void* funcPtr);
extern "C" void func_ov004_0215e148(void);

// USA: func_ov004_0215e25c
ARM void InitAndRegister_0215e25c(void* allocator, void* obj) {
    Template0215e25c local = data_ov004_0216fc40;
    void* block = _ZN13SafeAllocator8AllocateEj(allocator, sizeof(Template0215e25c));
    memcpy(block, &local, sizeof(Template0215e25c));
    func_ov011_02184a24(obj, block, 0x64);
    func_ov011_02184c28(obj, (void*)func_ov004_0215e148);
}
