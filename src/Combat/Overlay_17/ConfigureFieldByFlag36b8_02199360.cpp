#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c508(void* state);
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
struct PointerField32c_ffc0;
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
void CopyVec3(int* dst, int* src);
void InitStruct02070378(char* obj);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);

// USA: func_ov017_02199360  (semantic: ConfigureFieldByFlag36b8_02199360)
extern "C" ARM void func_ov017_02199360(void* obj) {
    if (!*(unsigned char*)((char*)obj + 0x36b8)) return;

    struct BattleStruct* battleStruct = GetBattleStruct();
    void* state = func_0202ae18();
    void* base = func_02012fe4();
    void* src = *(void**)((char*)obj + 0x36bc);
    void* fieldPtr = GetField0x3f8Address(battleStruct);
    void* ptr32c = GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);

    if (func_0202c508(state)) {
        CopyVec3((int*)((char*)base + 0x2774), (int*)((char*)src + 0x40));
        *(int*)((char*)base + 0x2780) = *(short*)((char*)src + 0x4c);
        InitStruct02070378((char*)fieldPtr);
        *(short*)((char*)fieldPtr + 0x0) = 0x2710;
        ((char*)fieldPtr)[0x2] = 1;
        ((char*)fieldPtr)[0x7] = 1;
        CopyVec3((int*)((char*)fieldPtr + 0x10), (int*)((char*)ptr32c + 0x44));
        *(short*)((char*)fieldPtr + 0x1c) = *(int*)((char*)ptr32c + 0x54);
        ((char*)base)[0x2788] = 1;
        func_ov017_021d1a18(1, -1, 1, 0);
    } else {
        InitStruct02070378((char*)fieldPtr);
        *(short*)((char*)fieldPtr + 0x0) = 0x170c;
        ((char*)fieldPtr)[0x2] = 1;
        ((char*)fieldPtr)[0x7] = 1;
        *(int*)((char*)fieldPtr + 0x10) = -0x7000;
        *(int*)((char*)fieldPtr + 0x14) = 0x2e1;
        *(int*)((char*)fieldPtr + 0x18) = 0x5e66;
        *(short*)((char*)fieldPtr + 0x1c) = 0x3244;
    }
}
