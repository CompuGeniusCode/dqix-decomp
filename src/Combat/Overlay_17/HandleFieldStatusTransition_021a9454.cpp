#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct PointerField32c_ffc0;
struct ResetObj020d7a5c;
struct Obj020d7aa0;

int GetGlobalField0x1c020421a0(void);
extern "C" void* func_02012fe4(void);
int GetFieldIfFlag4(char* obj);
struct ResetObj020d7a5c* GetGlobalResetObj020d7a50(void);
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
void ClearByteFlagAt0x154(unsigned char* obj);
int CallFunc020e0434With02153694(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void func_0204500c(void*, const char*, int, int);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
extern "C" int func_020457e0(void* obj);
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
extern "C" void VectorizedMemset(void*, int, int);
void ReinitController02043204(char* obj);
void SetByteFlagAt0x154(unsigned char* obj);

// USA: func_ov017_021a9454  (semantic: HandleFieldStatusTransition_021a9454)
extern "C" ARM void func_ov017_021a9454(char* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    char* g = (char*)GetGlobalField0x1c020421a0();
    func_02012fe4();
    int field = GetFieldIfFlag4((char*)battleStruct);
    int status = *(int*)(obj + 0x8);

    if (status == 0) {
        struct ResetObj020d7a5c* reset = GetGlobalResetObj020d7a50();
        TeardownAndResetState020d7aa0((struct Obj020d7aa0*)reset);
        void* p = GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);
        ClearByteFlagAt0x154((unsigned char*)p);

        int flag10 = *(int*)(obj + 0x10);
        char* buf = *(char**)(g + 0x5c);
        if (flag10 == 0) {
            sprintf(buf, (const char*)CallFunc020e0434With02153694(0x3a));
        } else {
            sprintf(buf, (const char*)CallFunc020e0434With02153694(0x3b));
            *(int*)(obj + 0xc) = 0x170c;
        }
        func_0204500c(g, buf, 0, 0xe3);
        *(unsigned char*)(g + 0x1000 + 0x9b2) = 0;
        *(int*)(g + 0x998) = 1;
        SetFlagsAt0x244((unsigned char*)field, 2);
        *(int*)(obj + 0x8) = 1;
        return;
    }

    if (status != 1 || *(int*)(g + 0x9a0) != 0) return;

    ClearFlagBits((unsigned char*)field, 2);
    if (func_020457e0(g) == 0) {
        GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);
        char* p3 = (char*)GetField0x3f8Address(battleStruct);
        VectorizedMemset(p3, 0, 0x70);
        p3[4] = 1;
        p3[8] = 1;
        p3[9] = 1;
        p3[0xb] = -1;
        *(int*)(p3 + 0x20) = -1;
        *(int*)(p3 + 0x24) = -1;
        *(int*)(p3 + 0x28) = -1;
        *(int*)(p3 + 0x2c) = -1;
        *(short*)(p3 + 0x1e) = -1;
        p3[0xc] = 0;
        *(short*)(p3 + 0x6c) = -1;
        *(short*)(p3 + 0x0) = (short)(*(int*)(obj + 0xc));
        p3[2] = 1;
        p3[7] = 1;

        if (*(int*)(obj + 0x10) == 0) {
            *(int*)(p3 + 0x10) = 0x100000;
            *(int*)(p3 + 0x14) = 0;
            *(int*)(p3 + 0x18) = 0x100000;
            *(short*)(p3 + 0x1c) = 0;
        } else {
            *(int*)(p3 + 0x10) = 0x5f0a;
            *(int*)(p3 + 0x14) = 0x3614;
            *(int*)(p3 + 0x18) = 0x570;
            *(short*)(p3 + 0x1c) = 0x4b66;
        }
        ReinitController02043204(g);
        obj[1] = 1;
        return;
    }

    ReinitController02043204(g);
    void* p = GetPointerAt0x32c((struct PointerField32c_ffc0*)battleStruct);
    SetByteFlagAt0x154((unsigned char*)p);
    obj[1] = 1;
}
