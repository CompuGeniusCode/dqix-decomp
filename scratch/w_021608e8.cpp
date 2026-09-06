#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_021608e8
ARM int StoreField99c_021608e8(void* obj) {
    int v = func_ov017_021d60f4(obj);
    *(int*)(GetGlobalField0x1c020421a0() + 0x99c) = v;
    return 1;
}
