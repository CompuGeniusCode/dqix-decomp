#include <globaldefs.h>
void ResetBattleSections0205e324(void*);
void ClearThreeWords0205e180(struct Struct0205e16c*);


// USA: func_0202c814
ARM void* ReleaseBattleArray0202c814(void* obj) {
    ResetBattleSections0205e324((void*)(obj));
    ClearThreeWords0205e180((struct Struct0205e16c*)((char*)obj + 0x1518));
    ClearThreeWords0205e180((struct Struct0205e16c*)((char*)obj + 0x150c));
    ClearThreeWords0205e180((struct Struct0205e16c*)((char*)obj + 0x1500));
    return obj;
}
