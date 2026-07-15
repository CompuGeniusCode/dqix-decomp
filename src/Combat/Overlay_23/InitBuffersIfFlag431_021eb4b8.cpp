#include <globaldefs.h>

extern "C" void func_ov023_021ecdfc(void*);
struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_ov023_021ecf78(void*);

// USA: func_ov023_021eb4b8
ARM void InitBuffersIfFlag431_021eb4b8(void* obj) {
    if (*(unsigned char*)((char*)obj + 0x431) == 0) return;
    func_ov023_021ecdfc(obj);
    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)((char*)obj + 0xc4));
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)((char*)obj + 0xc4));
    CallFunc0204b04cOverList0x98((Cont0205d274*)((char*)obj + 0xc4));
    func_ov023_021ecf78(obj);
}
