#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void _Z17SetXY1c4_02184bf0Pvss(void* obj, int x, int y);

// USA: func_ov011_02187f04  (semantic: SetXY1c4FromTagged_02187f04)
extern "C" ARM int func_ov011_02187f04(struct TaggedNumber02184c30* a) {
    int x = GetTaggedValueAsInt_02184c30(a);
    int y = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    _Z17SetXY1c4_02184bf0Pvss(func_ov017_021b2164(), x, y);
    return 1;
}
