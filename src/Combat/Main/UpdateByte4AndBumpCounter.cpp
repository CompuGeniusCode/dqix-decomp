#include <globaldefs.h>

extern "C" int func_020095b0(void* obj, int value);
extern "C" void func_0200961c(unsigned char* base, int startOffset);

struct Obj0200966c { char pad[0x4]; unsigned char byte4; };

// USA: func_0200966c  (semantic: UpdateByte4AndBumpCounter)
extern "C" ARM void func_0200966c(struct Obj0200966c* obj, int value) {
    if (value <= 0) {
        return;
    }
    if (value >= obj->byte4) {
        return;
    }
    int ret = func_020095b0(obj, value);
    obj->byte4 = value;
    if (ret < 0) {
        return;
    }
    func_0200961c((unsigned char*)obj, value);
}
