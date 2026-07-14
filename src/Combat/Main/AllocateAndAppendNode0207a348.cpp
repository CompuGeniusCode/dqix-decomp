#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct02030b7c { int field0; void* field4; };
void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct SearchNode0207afbc;
SearchNode0207afbc* FindNodeByName0207afbc(SearchNode0207afbc** head, const char* name);

struct NodeAAF90;
void AppendChildNode(struct NodeAAF90* parent, struct NodeAAF90* node);

void ResetBattleParamsBlock0207a060(void* p);

extern "C" void func_02036d88(void* node, void* buf);

struct S02037418;
void SetFieldAAndSync02037418(struct S02037418* obj, int val);

extern int data_02108e40;

struct Pair0207a348 {
    struct Struct02030b7c a;
    struct Struct02030b7c b;
};

// USA: func_0207a348
ARM int AllocateAndAppendNode0207a348(struct Pair0207a348* p, int count) {
    if (*(void**)((char*)&data_02108e40 + 8) == NULL) return 0;
    if (count < 2) return 0;

    void* name = GetField4IfField0Zero(&p->a);
    void* buf2 = GetField4IfField0Zero(&p->b);
    SearchNode0207afbc* node = FindNodeByName0207afbc(*(SearchNode0207afbc***)((char*)&data_02108e40 + 8), (const char*)name);
    if (node == NULL) return 0;

    void* allocated = (*(SafeAllocator**)((char*)&data_02108e40 + 0))->Allocate(0x104);
    ResetBattleParamsBlock0207a060(allocated);
    func_02036d88(node, allocated);
    SetFieldAAndSync02037418((struct S02037418*)allocated, 0x1f);
    memcpy((char*)allocated + 0xac, buf2, 0x20);
    AppendChildNode(*(struct NodeAAF90**)((char*)&data_02108e40 + 8), (struct NodeAAF90*)allocated);
    return 1;
}
