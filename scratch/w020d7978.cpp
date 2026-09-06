#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);
void InitObjState_021b2174(unsigned char* obj);
void CopyGlobalBlockAndDispatch_02165df4(SafeAllocator* a, void* target);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct S021b2ba0;
void SetNameChecked_021b2ba0(struct S021b2ba0* obj, char* src);

void SetFields30And34_021b2bd0(void* obj, int a, int b);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

extern struct Obj0205eaa0 data_02108760;
extern char data_020f2334[];

// USA: func_020d7978
ARM void InitAndAppendEntry020d7978(void) {
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    int base = func_ov017_0218b5b0();
    char* p = (char*)base + 0x3000;
    struct TailList020469b4* list = *(struct TailList020469b4**)(p + 0x6fc);
    unsigned char* obj = *(unsigned char**)(p + 0xb4c);
    InitObjState_021b2174(obj);
    SetNameChecked_021b2ba0((struct S021b2ba0*)obj, data_020f2334);
    int fn = (int)CopyGlobalBlockAndDispatch_02165df4;
    SetFields30And34_021b2bd0(obj, fn, 4);
    AppendNodeToTail(list, (struct TailNode020469b4*)obj);
}
