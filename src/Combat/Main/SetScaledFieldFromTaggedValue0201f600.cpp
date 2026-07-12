#include <globaldefs.h>

struct TaggedValue02030b44;
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);
extern int data_020fdc4c;

// USA: func_0201f600
ARM int SetScaledFieldFromTaggedValue0201f600(struct TaggedValue02030b44* v) {
    float scaled = 4096.0f * GetTaggedValueAsFloat(v);
    *(int*)(*(char**)((char*)&data_020fdc4c + 0x10) + 0x38) = (int)scaled;
    return 1;
}
