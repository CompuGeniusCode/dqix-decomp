#include <globaldefs.h>

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
void UpdateEntryAndScale_0215e2a8(char* base);

// USA: func_ov003_0215ca1c  (semantic: ResetEntryBuffersAndScale_0215ca1c)
extern "C" ARM void func_ov003_0215ca1c(char* obj) {
    if (*(unsigned char*)(obj + 0x3bc) == 0) return;
    ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + 0x98));
    CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + 0x98));
    func_0205da88(obj + 0x98, 1, 2, 1);
    CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + 0x98));
    UpdateEntryAndScale_0215e2a8(obj);
}
