#include <globaldefs.h>

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
struct StateStruct_02184c14;
void SetField1d8FromGlobalU16_02184c14(struct StateStruct_02184c14* obj);

extern "C" void* func_ov017_021b2164(void);
extern "C" void MapVRAMBanksToSubBG(int v);

struct Table4_02188904 { int v[4]; };
extern struct Table4_02188904 data_ov011_02188904;

// USA: func_ov011_02188090
ARM int DispatchTableByTaggedIndex_02188090(struct TaggedNumber02184c30* p) {
    void* ctx = func_ov017_021b2164();
    SetField1d8FromGlobalU16_02184c14((struct StateStruct_02184c14*)ctx);
    int idx = GetTaggedValueAsInt_02184c30(p);
    struct Table4_02188904 table = data_ov011_02188904;
    MapVRAMBanksToSubBG(table.v[idx]);
    return 1;
}
