#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetField0x3f8Address(struct BattleStruct* battleStruct);
void CopyVec3(int* dst, int* src);
extern "C" void* func_02012fe4();
struct S_bc7c;
void SetField0x27d8(struct S_bc7c* obj, unsigned short val);
struct S_bc88;
void SetField0x27da(struct S_bc88* obj, unsigned short val);

struct Data02109bf4 {
    unsigned char pad[0xc8];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
};
extern struct Data02109bf4 data_02109bf4;

// USA: func_020a9d78
ARM int CopyBlobIntoBattleStruct020a9d78(void* srcRaw) {
    char* src = (char*)srcRaw;
    struct BattleStruct* battleStruct = GetBattleStruct();
    char* dst = (char*)GetField0x3f8Address(battleStruct);

    *(unsigned short*)(dst + 0x0) = *(unsigned short*)(src + 0x0);
    CopyVec3((int*)(dst + 0x10), (int*)(src + 0x4));

    *(short*)(dst + 0x1c) = *(short*)(src + 0x2);
    *(unsigned char*)(dst + 0x7) = 1;

    void* g = func_02012fe4();
    SetField0x27d8((struct S_bc7c*)g, *(unsigned short*)(src + 0x12));
    SetField0x27da((struct S_bc88*)g, *(unsigned short*)(src + 0x10));

    data_02109bf4.b3 = (*(unsigned char*)(src + 0x14) != 0);

    char* region = (char*)battleStruct + 0x7e78;
    *(short*)(region + 0x0) = *(short*)(src + 0x16);
    *(short*)(region + 0x2) = *(short*)(src + 0x18);
    *(short*)(region + 0x4) = *(short*)(src + 0x1a);
    *(signed char*)(region + 0x6) = *(signed char*)(src + 0x15);
    return 1;
}
