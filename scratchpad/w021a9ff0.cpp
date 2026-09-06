#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

int GetWord0x0(int* obj);
struct BattleStruct* GetBattleStruct();
void InitObjState_021b2174(unsigned char* obj);
struct S021b2ba0;
void SetNameChecked_021b2ba0(struct S021b2ba0* obj, char* src);
void SetFields30And34_021b2bd0(void* obj, int a, int b);
struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(struct HeadList020469f8* list, struct HeadNode020469f8* node);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
void SetBothCounters(void* obj, int value, int frames);
struct SetFlagStruct;
void SetFlag0x9c6(struct SetFlagStruct* p, int value);
extern char data_ov017_021d7831;
void CopyGlobalBlockAndDispatch_02165df4(SafeAllocator*, void*);

// USA: func_ov017_021a9ff0
ARM void InitAndLinkObjState_021a9ff0(int shouldPrepend) {
    char* base = (char*)(long)GetWord0x0((int*)GetBattleStruct());
    struct SetFlagStruct* flagObj = *(struct SetFlagStruct**)(base + 0x3000 + 0x6d0);
    void* list = *(void**)(base + 0x3000 + 0x6fc);
    unsigned char* obj = *(unsigned char**)(base + 0x3000 + 0xb4c);
    InitObjState_021b2174(obj);
    SetNameChecked_021b2ba0((struct S021b2ba0*)obj, &data_ov017_021d7831);
    SetFields30And34_021b2bd0(obj, (int)(long)CopyGlobalBlockAndDispatch_02165df4, 4);
    if (shouldPrepend) {
        PrependNodeToHead((struct HeadList020469f8*)list, (struct HeadNode020469f8*)obj);
    } else {
        AppendNodeToTail((struct TailList020469b4*)list, (struct TailNode020469b4*)obj);
    }
    SetBothCounters(base, -16, 0x19);
    SetFlag0x9c6(flagObj, 1);
}
