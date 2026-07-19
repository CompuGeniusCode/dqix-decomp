#include <globaldefs.h>

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8*, int, int);

struct SrcPair_021f7d14 { int a; int b; };

// USA: func_ov023_021f7d14
ARM int SetShortsAndDispatch_021f7d14(char* dest, struct SrcPair_021f7d14* src) {
    *(short*)(dest + 0x50) = (short)(src->a >> 12);
    *(short*)(dest + 0x52) = (short)(src->b >> 12);
    return DispatchViaTable0204b5e8((struct Obj0204b5e8*)(dest + 0x28), *(short*)(dest + 0x50), *(short*)(dest + 0x52));
}
