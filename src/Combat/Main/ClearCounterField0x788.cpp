#include <globaldefs.h>

extern "C" void func_020d9788(int);

struct Obj0202fa00 {
    char pad0[0x124];
    void* field124;
    char pad128[0x788 - 0x128];
    unsigned int field788;
    unsigned int field78c;
};

// USA: func_0202fa00
ARM void ClearCounterField0x788(struct Obj0202fa00* obj) {
    if (obj->field788 != 0) obj->field788 = 0;
    obj->field78c &= ~0x4;
    if (obj->field124 == NULL) return;
    func_020d9788(1);
}
