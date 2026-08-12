#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* obj, int key);
extern int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void* func_ov023_021fa598(void* p);
int GetGlobalField0x1c020421a0();
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);

struct Field998_021873c4 { char pad[0x998]; int field998; };
struct Field9d2_021873c4 { char pad[0x9d2]; unsigned char field9d2; };

// USA: func_ov011_021873c4
extern "C" ARM int func_ov011_021873c4(struct TaggedNumber02184c30* a) {
    int v0 = GetTaggedValueAsInt_02184c30(a);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    void* node = func_ov023_021f6880(obj, v0);
    if (!node) return 1;
    if (ScaleStatsIfType12_021f6f10(node) != 4) return 1;
    void* p = func_ov023_021fa598(node);
    if (!p) return 1;
    int field = GetGlobalField0x1c020421a0();
    void* entry = FindEntryByKey((struct TableA68*)p, (short)v1);
    func_0204500c((void*)field, (char*)entry, 0, 0xe3);
    ((struct Field998_021873c4*)field)->field998 = 1;
    ((struct Field9d2_021873c4*)(field + 0x1000))->field9d2 = 1;
    return 1;
}
