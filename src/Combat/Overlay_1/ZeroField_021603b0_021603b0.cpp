#include <globaldefs.h>

void* GetData02107930(void);
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_021603b0
ARM int ZeroField_021603b0_021603b0(void* obj) {
    int* p = (int*)GetData02107930();
    func_ov017_021d60f4(obj);
    *(int*)((char*)p + 0x90) = 0;
    return 1;
}
