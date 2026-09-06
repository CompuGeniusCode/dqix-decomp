#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

struct TailNode020469b4 { unsigned char pad0[2]; unsigned char inList; unsigned char pad3; void* next; };
struct TailList020469b4 { void* head; void* tail; };
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

struct Obj021ba90c;
extern void InitState16_021ba90c(Obj021ba90c* p);

// USA: func_ov017_021ba8e0  (semantic: InitAndAppendState16_021ba8e0)
extern "C" ARM void func_ov017_021ba8e0(unsigned char* base) {
    GetGlobalField0x1c020421a0();
    InitState16_021ba90c(*(Obj021ba90c**)(base + 0x3000 + 0x72c));
    TailList020469b4* list = *(TailList020469b4**)(base + 0x3000 + 0x6fc);
    TailNode020469b4* node = *(TailNode020469b4**)(base + 0x3000 + 0x72c);
    AppendNodeToTail(list, node);
}
