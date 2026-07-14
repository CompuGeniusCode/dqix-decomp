#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void CopyVec3(int* dst, int* src);

struct Vec3i020a7eb8 {
    int x;
    int y;
    int z;
};

struct Obj020a7eb8 {
    char unk0[0x44];
    struct Vec3i020a7eb8 pos;   // 0x44
    char unk1[0x140 - 0x50];
    int field140;               // 0x140
};

extern "C" void func_02032fdc(struct Obj020a7eb8* obj, int a1, int a2);

// USA: func_020a7eb8
ARM void OffsetPositionYAndDispatch(struct Obj020a7eb8* obj) {
    GetBattleStruct();
    struct Vec3i020a7eb8 tmp = obj->pos;
    tmp.y += obj->field140;
    CopyVec3((int*)&obj->pos, (int*)&tmp);
    func_02032fdc(obj, 1, 0);
    CopyVec3((int*)&tmp, (int*)&obj->pos);
    tmp.y -= obj->field140;
    CopyVec3((int*)&obj->pos, (int*)&tmp);
}
