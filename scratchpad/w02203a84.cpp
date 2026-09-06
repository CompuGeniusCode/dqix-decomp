#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" int func_ov031_022039b0(int, int, int, int);
extern "C" void* memmove(void*, const void*, unsigned int);

// USA: func_ov031_02203a84
#pragma optimize_for_size off
ARM int DrainOrForwardBuffer_02203a84(int a0, int a1) {
    void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
    if (mgr == NULL) goto retZero;
    {
    int field60 = *(int*)((char*)mgr + 0x60);
    if (field60 == 0) goto fieldZeroCase;
    {
    int field5c = *(int*)((char*)mgr + 0x5c);
    int result = func_ov031_022039b0(field5c, field60, a0, a1);
    field60 = *(int*)((char*)mgr + 0x60);
    if ((unsigned int)result >= (unsigned int)field60) goto resultHsCase;
    field5c = *(int*)((char*)mgr + 0x5c);
    memmove((void*)field5c, (void*)(field5c + result), field60 - result);
    *(int*)((char*)mgr + 0x60) = *(int*)((char*)mgr + 0x60) - result;
    return 0;
resultHsCase:
    *(int*)((char*)mgr + 0x60) = 0;
    return result - field60;
    }
fieldZeroCase:
    return func_ov031_022039b0(a0, a1, 0, 0);
    }
retZero:
    return 0;
}
