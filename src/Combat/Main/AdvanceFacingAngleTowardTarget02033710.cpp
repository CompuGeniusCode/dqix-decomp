#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" int func_02030f30(int angle);
struct S_377d4;
extern "C" int _ZNK8Object3D25IsTransitioningAnimationsEv(struct S_377d4* obj);
struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
extern "C" int func_02030cd8(int a, int b);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern char data_020efa3c;

struct Vec3_33710 { int x; int y; int z; };
struct Flags0xc4_33710 { unsigned short low : 15; unsigned short hi : 1; };

struct Obj02033710 {
    char pad0[0x14];
    char* name;             // 0x14
    char pad1[0x38];        // 0x18
    struct Vec3_33710 pos;  // 0x50
    char pad2[0x52];        // 0x5c
    short angleAE;          // 0xae
    short scaleB0;           // 0xb0
    char pad3[0xc];         // 0xb2
    unsigned char stateBe;  // 0xbe
    char pad4[5];           // 0xbf
    struct Flags0xc4_33710 flagsC4; // 0xc4
};

// USA: func_02033710
ARM void AdvanceFacingAngleTowardTarget(struct Obj02033710* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    if (obj->stateBe == 4 || obj->stateBe == 6) {
        return;
    }
    unsigned int scaleCount = GetBattleScaleCount(battleStruct);
    int scaled = obj->scaleB0 * (int)scaleCount;
    struct Vec3_33710 tmp = obj->pos;
    int d = func_02030cd8(tmp.y, obj->angleAE);
    int atTarget = 1;
    if (d > 0) {
        if (d < scaled) {
            tmp.y = obj->angleAE;
        } else {
            tmp.y += scaled;
            atTarget = 0;
        }
    } else if (d < 0) {
        int ad = -d;
        if (ad < scaled) {
            tmp.y = obj->angleAE;
        } else {
            tmp.y -= scaled;
            atTarget = 0;
        }
    }
    tmp.y = func_02030f30(tmp.y);
    _ZN8Vector3iaSERKS_((int*)&obj->pos, (int*)&tmp);
    if (atTarget) {
        if (obj->flagsC4.hi) {
            if (!_ZNK8Object3D25IsTransitioningAnimationsEv((struct S_377d4*)obj)) {
                obj->flagsC4.hi = 0;
                if (obj->stateBe == 0) {
                    if (obj->name != NULL) {
                        if (strcmp(obj->name, &data_020efa3c) == 0) {
                            SetByte0xbeShiftPrev((struct Bytes02033b88*)obj, 0);
                        }
                    }
                }
            }
        }
    }
}
