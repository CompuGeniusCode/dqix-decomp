#include <globaldefs.h>

struct Obj0205dee8 {
    char pad0[0xb0];
    unsigned char fieldB0;           // 0xb0
};

extern "C" void func_0205d904(struct Obj0205dee8*);

// USA: func_0205dee8
ARM void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val) {
    obj->fieldB0 = val;
    func_0205d904(obj);
}
