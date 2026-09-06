#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_02012fe4(void* unused);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);
extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int id, int flags);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
extern int data_020e8d48;

struct Vec3Local_0208f748 { int x, y, z; };
struct Field0xc_0208f748 { char pad[0xc]; unsigned char flag:4; };

// USA: func_0208f748  (semantic: ResyncCombatantWithGrottoPosition_0208f748)
extern "C" ARM int func_0208f748(unsigned char* obj) {
    void* p = func_02012fe4(obj);
    Field0xc_0208f748* q = (Field0xc_0208f748*)*(void**)((char*)p + 8);
    if (q->flag != 0) return 0;
    BattleStruct* battle = GetBattleStruct();
    GetCombatantAtField0x3ac(battle);
    func_ov017_0218b5b0();
    func_0202ae18();
    GrottoStruct* grotto = GetGrottoStruct(battle);
    Vec3Local_0208f748 tmp1;
    _ZN8Vector3iaSERKS_((int*)&tmp1, (int*)((char*)grotto + 0x10));
    Vec3Local_0208f748 tmp0 = *(Vec3Local_0208f748*)&data_020e8d48;
    _ZN8Vector3iaSERKS_((int*)(obj + 0x4c), (int*)&tmp1);
    _ZN8Object3D8SetScaleEPK8Vector3i(obj + 8, (int*)&tmp0);
    _ZN8Object3D21MaybeSetBCFGAnimationEii(obj + 8, 0, 0);
    _ZN8Object3D11MakeVisibleEv(obj + 8);
    obj[0xb6] = 1;
    return 1;
}
