#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z19GetBattleScaleCountP12BattleStruct(void*);
extern "C" void _Z15Forward0204359cPvi(void*, int);
extern "C" void func_020439b0(void*, int);
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(void*);
extern "C" void _Z23EmptyDestructor0205cb60Pv(void*);

// USA: func_ov013_02184aec  (semantic: SetupBattleScaleData02184aec)
extern "C" ARM void func_ov013_02184aec(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char tag = o[0x63c];
    switch (tag) {
        case 0: case 5: case 6: return;
    }

    void* battle = _Z15GetBattleStructv();
    void* field = _Z26GetGlobalField0x1c020421a0v();
    int count = _Z19GetBattleScaleCountP12BattleStruct(battle);
    _Z15Forward0204359cPvi(field, count);
    func_020439b0(field, 0);
    _Z19InitEntries0205d2bcP11Obj0205d2bc(o + 0x38);
    _Z23EmptyDestructor0205cb60Pv(o + 0x3d4);
}
