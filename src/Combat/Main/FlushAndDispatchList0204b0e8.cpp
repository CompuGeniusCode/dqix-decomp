#include <globaldefs.h>

extern "C" void func_0204b04c(void*, int);
extern "C" void func_0204b088(void*, int);

struct List0204b0e8 {
    char pad0[0x14];
    void* field14;
};

// USA: func_0204b0e8
ARM void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf) {
    if (buf == NULL) buf = obj->field14;
    if (buf == NULL) return;
    func_0204b04c(obj, (int)buf);
    func_0204b088(obj, (int)buf);
}
