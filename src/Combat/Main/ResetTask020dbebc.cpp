#include <globaldefs.h>

struct Obj020dbf70;
struct Struct020dbd9c;
struct BattleTask020dbedc;

void ReleaseHandle020dbf70(struct Obj020dbf70* o);
void InitStruct020dbd9c(struct Struct020dbd9c* p);
void UpdateTaskState020dbedc(struct BattleTask020dbedc* a);

// USA: func_020dbebc
ARM void ResetTask020dbebc(void* a) {
    ReleaseHandle020dbf70((struct Obj020dbf70*)a);
    UpdateTaskState020dbedc((struct BattleTask020dbedc*)a);
    InitStruct020dbd9c((struct Struct020dbd9c*)a);
}
