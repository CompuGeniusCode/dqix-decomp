#include <globaldefs.h>

struct TableStruct0215acd4 { void* unused0; char* base; };
extern TableStruct0215acd4 data_ov001_02165880;
extern "C" void func_ov001_0215acb4(void* entry);

// USA: func_ov001_0215acd4
ARM void CallByIndex_0215acd4(int idx) {
    char* base = data_ov001_02165880.base;
    if (base == NULL) return;
    func_ov001_0215acb4(base + (idx << 4));
}
