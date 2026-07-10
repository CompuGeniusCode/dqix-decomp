#include <globaldefs.h>

struct Struct02030774 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
};

extern "C" int func_020307d0(struct Struct02030774*, int);

// USA: func_02030774
ARM int RunLoopIfValid02030774(struct Struct02030774* p) {
    if (p->field0 <= 0 || p->fieldC == 0 || p->field10 <= 0) {
        return 0;
    }
    p->field28 = 0;
    while (func_020307d0(p, 1) != 0) {
    }
    return 1;
}
