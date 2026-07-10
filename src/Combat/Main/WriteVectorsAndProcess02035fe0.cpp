#include <globaldefs.h>

struct S02036000;
struct Obj02036024;
struct S02036060;

void WriteVec3ToReg02036000(struct S02036000* obj);
void ProcessOptionalPtrFields02036024(struct Obj02036024* obj);
void WriteVec3ShortToReg02036060(struct S02036060* obj);

// USA: func_02035fe0
ARM void WriteVectorsAndProcess02035fe0(void* obj) {
    WriteVec3ToReg02036000((struct S02036000*)obj);
    ProcessOptionalPtrFields02036024((struct Obj02036024*)obj);
    WriteVec3ShortToReg02036060((struct S02036060*)obj);
}
