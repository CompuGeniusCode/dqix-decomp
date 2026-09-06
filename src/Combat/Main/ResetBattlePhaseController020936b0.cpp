#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

ARM int GetGlobal02109400(void);
extern "C" ARM void func_02094ab0(void* obj);
extern "C" ARM int _Z26GetGlobalField0x1c020421a0v();
extern "C" ARM void _Z24ReinitController02043204Pc(char* obj);
ARM void ClearSubstructBytes(void* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020936b0
ARM void ResetBattlePhaseController020936b0(void* obj) {
    unsigned char* self = (unsigned char*)obj;
    func_02094ab0((void*)GetGlobal02109400());
    self[0x37] &= ~4;
    _Z24ReinitController02043204Pc((char*)_Z26GetGlobalField0x1c020421a0v());
    *(short*)(self + 0x30) = -1;
    self[0x34] = 4;
    self[0x35] = 0;
    ClearSubstructBytes(GetBattleStruct());
}
