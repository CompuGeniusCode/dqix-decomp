#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov011_021842a0(void* obj);

// USA: func_ov011_021845c8
ARM void InitAndCreateTypeB021845c8(char* obj, void* bufferStart, unsigned int bufferSize) {
    func_ov011_021842a0(obj);
    ((SafeAllocator*)(obj + 4))->CreateTypeB(bufferStart, bufferSize, 4);
}
