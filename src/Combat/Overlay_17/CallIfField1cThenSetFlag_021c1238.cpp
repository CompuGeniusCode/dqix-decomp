#include <globaldefs.h>

struct S021c1238 { unsigned char pad[0x1c]; void* f1c; };

extern "C" void func_ov008_021845ac(void*);
extern "C" void func_ov017_021c07d0(S021c1238*);

// USA: func_ov017_021c1238
ARM void CallIfField1cThenSetFlag_021c1238(S021c1238* obj) {
    void* p = obj->f1c;
    if (p) func_ov008_021845ac(p);
    func_ov017_021c07d0(obj);
    ((unsigned char*)obj)[1] = 1;
}
