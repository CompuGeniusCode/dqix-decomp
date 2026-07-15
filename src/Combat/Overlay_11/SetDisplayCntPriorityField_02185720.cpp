#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);

// USA: func_ov011_02185720
ARM int SetDisplayCntPriorityField_02185720(TaggedNumber02184c30* a) {
    int which = GetTaggedValueAsInt_02184c30(a);
    int val = GetTaggedValueAsInt_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    if (which == 0) {
        unsigned int* reg = (unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | (val << 8);
    } else if (which == 1) {
        unsigned int* reg = (unsigned int*)0x4001000;
        *reg = (*reg & ~0x1f00) | (val << 8);
    }
    return 1;
}
