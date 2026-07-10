#include <globaldefs.h>

extern "C" int func_0207e97c(void* obj);
extern "C" void func_020b66f4(void* dst, int a, int b, int c);

struct Obj0207e924 {
    char pad0[0x54];
    void* field_54;
    char pad1[0x50];
    signed int flag : 1;
};

// USA: func_0207e924
ARM int InvokeField54IfFlag0xa8Bit0Set(struct Obj0207e924* obj, int prep, int a, int b, int c) {
    if (obj->flag == 0) return 0;
    if (prep != 0) {
        if (func_0207e97c(obj) == 0) return 0;
    }
    func_020b66f4(obj->field_54, a, b, c);
    return 1;
}
