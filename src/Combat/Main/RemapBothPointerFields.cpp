#include <globaldefs.h>

extern "C" void* func_020e523c(void* a, void* b, int c);

struct Pair020e5204 {
    void* field0;
    void* field4;
};

// USA: func_020e5204
ARM int RemapBothPointerFields(void* arg0, struct Pair020e5204* p) {
    p->field0 = func_020e523c(arg0, p->field0, 0);
    p->field4 = func_020e523c(arg0, p->field4, 0);
    return 1;
}
