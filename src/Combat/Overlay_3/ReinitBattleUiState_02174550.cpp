#include <globaldefs.h>

struct Obj0208203c;
struct Cont0207fe44;
struct Outer020e28dc;
struct Obj020e25e8;

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
void ResetWithSub0208203c(struct Obj0208203c* obj);
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);
extern "C" void func_ov003_021749c0(char* base);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);
extern "C" void func_ov003_02175cb0(char* base, int flag);

// USA: func_ov003_02174550  (semantic: ReinitBattleUiState_02174550)
extern "C" ARM void func_ov003_02174550(char* base) {
    if (*(unsigned char*)(base + 0x1000 + 0x4e) != 0) return;
    *(unsigned char*)(base + 0x1000 + 0x4e) = 1;

    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    ResetWithSub0208203c((struct Obj0208203c*)(base + 0x88c));

    *(int*)(base + 0xff8) = 0;
    CallFunc0204c804OverAllElems(*(struct Cont0207fe44**)(base + 0x89c));

    *(unsigned char*)(base + 0x1000 + 0x3e) = 9;
    *(unsigned char*)(base + 0x1000 + 0x3f) = 0;
    if (*(unsigned short*)(base + 0x1000 + 0x46) & 0x80) {
        func_ov003_021749c0(base);
    }

    if (*(struct Outer020e28dc**)base != NULL && GetInnerFlagBit0020e28dc(*(struct Outer020e28dc**)base)) {
        ResetSelectionState020e25e8((struct Obj020e25e8*)(*(void**)base));
    }

    if (*(unsigned char*)(base + 0x1000 + 0x4f) != 0) {
        func_ov003_02175cb0(base, 1);
    }
}
