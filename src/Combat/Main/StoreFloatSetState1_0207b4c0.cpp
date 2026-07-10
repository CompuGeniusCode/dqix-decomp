#include <globaldefs.h>

struct TaggedValue02030b44;
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

extern int data_02108e60;

// USA: func_0207b4c0
ARM int StoreFloatSetState1_0207b4c0(struct TaggedValue02030b44* v, int cond) {
    if (cond > 0) {
        *(float*)(*(char**)&data_02108e60 + 0x308) = GetTaggedValueAsFloat(v);
    }
    *(int*)(*(char**)&data_02108e60 + 0x304) = 1;
    return 1;
}
