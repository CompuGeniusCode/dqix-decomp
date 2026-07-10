#include <globaldefs.h>

extern int data_02111754;

struct MakeDataRefSrc020ccfd4 { char unk[0x18]; int f18; };
struct MakeDataRefPair020ccfd4Result { void* ptr; int value; };

// USA: func_020ccfd4
ARM struct MakeDataRefPair020ccfd4Result MakeDataRefPair020ccfd4(struct MakeDataRefSrc020ccfd4* src) {
    struct MakeDataRefPair020ccfd4Result result;
    result.ptr = &data_02111754;
    result.value = src->f18;
    return result;
}
