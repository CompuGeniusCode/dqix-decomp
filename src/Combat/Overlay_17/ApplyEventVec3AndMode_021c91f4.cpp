#include <globaldefs.h>

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
void CopyVec3(int* dst, int* src);
struct Obj02033874;
void SetVecYFromValue02033874(Obj02033874* obj, int arg);
void TrySetMode02076ccc(void*, int);

struct LocalEvt021c91f4 {
    unsigned char pad0[8];
    unsigned short field8;
    short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c91f4
ARM void ApplyEventVec3AndMode_021c91f4(int unused0, LocalEvt021c91f4* evt) {
    int local[3];
    if (!func_ov017_021d446c((char*)evt + 4, local, -1)) return;
    if (*(int*)((char*)local[2] + 0x130) == 9) return;
    int vec[3];
    vec[0] = evt->fieldC;
    vec[2] = evt->field10;
    int y = evt->fieldA;
    unsigned short h = evt->field8;
    vec[1] = *(int*)((char*)local[2] + 0x48);
    CopyVec3((int*)((char*)local[2] + 0x44), vec);
    SetVecYFromValue02033874((Obj02033874*)local[2], y);
    *(unsigned short*)((char*)local[2] + 0x100 + 0x64) = h;
    TrySetMode02076ccc((void*)local[2], 2);
}
