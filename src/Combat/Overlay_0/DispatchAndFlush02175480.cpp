#include <globaldefs.h>

struct Obj0204b8d0;
void DispatchEntry0204b8d0(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8*, void*);

// USA: func_ov000_02175480
ARM void DispatchAndFlush02175480(void* obj) {
    DispatchEntry0204b8d0((struct Obj0204b8d0*)((char*)obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    FlushAndDispatchList0204b0e8((struct List0204b0e8*)((char*)obj + 0x8c4), 0);
}
