#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator data_02153680;

// USA: func_020e50ec
ARM void CreateAndResetAllocator020e50ec(void* bufferStart, unsigned int bufferSize) {
    data_02153680.CreateTypeA(bufferStart, bufferSize);
    data_02153680.Reset();
}
