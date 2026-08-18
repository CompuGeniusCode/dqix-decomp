#include <globaldefs.h>

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
extern "C" void func_ov008_02188730(void* obj);
extern "C" void func_ov008_02188934(void* obj);
struct Obj021889f8;
void ConfigureSubsystem_021889f8(struct Obj021889f8* obj);
extern "C" void func_ov008_02188870(void* obj);
void InitBuffersIfFlag431_021eb4b8(void* obj);

// USA: func_ov008_02184878
extern "C" ARM void func_ov008_02184878(char* obj) {
    signed char state = *(signed char*)(obj + 0xb10);
    if (state == 0 || state == 1 || state == 0xe) return;
    if (*(void**)(obj + 0xb08) == 0) {
        ClearBuffers0204b010OverList0x98((Cont0205d1e0*)(obj + 0x130));
        CallFunc0204c8f0OverList0x9c((Cont0205d228*)(obj + 0x130));
        CallFunc0204b04cOverList0x98((Cont0205d274*)(obj + 0x130));
    }
    if (*(int*)(obj + 0xb24) == 1) return;
    if (*(signed char*)(obj + 0xb10) == 3 && *(unsigned char*)(obj + 0xb11) < 1) return;
    func_ov008_02188730(obj);
    func_ov008_02188934(obj);
    ConfigureSubsystem_021889f8((struct Obj021889f8*)obj);
    func_ov008_02188870(obj);
    if (*(void**)(obj + 0xb08) != 0) {
        InitBuffersIfFlag431_021eb4b8(*(void**)(obj + 0xb08));
    }
}
