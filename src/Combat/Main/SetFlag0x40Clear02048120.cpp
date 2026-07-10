#include <globaldefs.h>

extern "C" void func_02032e58(void* obj);

struct Obj02048120 {
    unsigned short flags;   // 0x0
    char pad[0x12e];        // 0x2..0x12f
    void* field130;         // 0x130
};

// USA: func_02048120
ARM void SetFlag0x40Clear02048120(struct Obj02048120* obj) {
    func_02032e58(obj);
    obj->flags |= 0x40;
    obj->field130 = 0;
}
