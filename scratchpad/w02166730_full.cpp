#include <globaldefs.h>

extern char* data_ov004_0217101c;
extern "C" void* func_ov023_021f6524(void* ctx, int value);

struct Node02166730 { char pad[0x5c]; short field5c; short field5e; };

struct Obj021f9bdc;
void DivModField26_021f9bdc(struct Obj021f9bdc* o, int divisor);
extern "C" int func_ov023_021f98e0(void* node, void* obj);

struct Obj021f9bb0;
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);
struct Obj021f9bc0;
unsigned short GetField2a_021f9bc0(struct Obj021f9bc0* obj);
struct Obj9b6c;
unsigned int GetTableEntry_021f9b6c(struct Obj9b6c* obj, unsigned int a, unsigned int b);

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int key);
int ScaleStatsIfType12_021f6f10(void* self);
void* GetLinkedNodeIfKind6_021f9cb8(void* unused, void* other, void* node);
extern "C" int func_ov023_021f88b8(void* obj, void* param1, int id);

// USA: func_ov004_02166730
ARM int SetTableEntryFieldsAndDispatch_02166730(void* obj, short key) {
    void* found = *(void**)(data_ov004_0217101c + 8);
    short index = 0;
    while (found != NULL) {
        if (*(short*)((char*)found + 0) == key) break;
        index++;
        found = *(void**)((char*)found + 8);
    }

    short v6 = index / 8;
    short v7 = index % 8;
    Node02166730* node = (Node02166730*)func_ov023_021f6524(obj, 0x5b);
    if (node) {
        short old5e = node->field5e;
        node->field5c = v6;
        node->field5e = old5e;
        DivModField26_021f9bdc((struct Obj021f9bdc*)node, (unsigned short)v7);
        func_ov023_021f98e0(node, obj);
    }

    unsigned int idx = GetShort28_021f9bb0((struct Obj021f9bb0*)node);
    unsigned short field2a = GetField2a_021f9bc0((struct Obj021f9bc0*)node);
    unsigned int entry = GetTableEntry_021f9b6c((struct Obj9b6c*)node, idx, field2a);

    void* base = func_ov011_021849c8(obj);
    void* n2 = func_ov023_021f6880(base, entry);
    if (!n2) return (int)n2;

    int type = ScaleStatsIfType12_021f6f10(n2);
    if (type != 8) return type;

    void* result = GetLinkedNodeIfKind6_021f9cb8(node, obj, n2);
    if (!result) return (int)result;

    return func_ov023_021f88b8(result, obj, 0x8000);
}
