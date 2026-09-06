#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_0215e938
ARM int StoreField_0215e938_0215e938(void* obj) {
    int r = GetGlobalField0x1c020421a0();
    *(unsigned char*)(r + 0x1000 + 0x9ae) = func_ov017_021d60f4(obj);
    return 1;
}
