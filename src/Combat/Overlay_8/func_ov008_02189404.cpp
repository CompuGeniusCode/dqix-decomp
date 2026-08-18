#include <globaldefs.h>

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
extern "C" void func_ov008_0218aee4(void* obj);
extern "C" void func_ov008_02184878(void* obj);

struct Flags02189404 { char pad[0xec0]; unsigned char flagEc0 : 1; };

// USA: func_ov008_02189404
extern "C" ARM void func_ov008_02189404(char* obj) {
    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + 0x18));
    CallFunc0204c8f0OverList0x9c((struct Cont0205d228*)(obj + 0x18));
    func_0205da88(obj + 0x18, 1, 2, 1);
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + 0x18));
    func_ov008_0218aee4(obj);
    if (*(signed char*)(obj + 0xe9b) == 0) return;
    if (!((struct Flags02189404*)obj)->flagEc0) return;
    func_ov008_02184878(obj + 0x2a8);
}
