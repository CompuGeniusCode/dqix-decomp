#include <globaldefs.h>

struct Obj02048120;
void SetFlag0x40Clear02048120(struct Obj02048120*);

// USA: func_020489bc
ARM void SetFlag0x80Reset020489bc(void* obj) {
    SetFlag0x40Clear02048120((struct Obj02048120*)obj);
    *(unsigned short*)obj |= 0x80;
    *(int*)((char*)obj + 0x13c) = 0;
    *(int*)((char*)obj + 0x138) = 0;
    *(char*)((char*)obj + 0x140) = 0;
}
