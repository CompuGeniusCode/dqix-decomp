#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);
int GetGlobalField0x1c020421a0();

// USA: func_ov011_02188158  (semantic: SetGlobalFlagByte9caFromTagged_02188158)
extern "C" ARM int func_ov011_02188158(TaggedNumber02184c30* a) {
    int v = GetTaggedValueAsInt_02184c30(a);
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    *(unsigned char*)(g + 0x1000 + 0x9ca) = (v != 0) ? 1 : 0;
    return 1;
}
