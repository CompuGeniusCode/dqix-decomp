#include <globaldefs.h>

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
void StoreGlobalHalf2_02184c00(void* obj);

extern "C" void* func_ov017_021b2164(void);
extern "C" void func_020c3b64(int v);

struct Table17_02188954 { int v[17]; };
extern struct Table17_02188954 data_ov011_02188954;

// USA: func_ov011_02188030
ARM int DispatchTable17ByTaggedIndex_02188030(struct TaggedNumber02184c30* p) {
	StoreGlobalHalf2_02184c00(func_ov017_021b2164());
	int idx = GetTaggedValueAsInt_02184c30(p);
	struct Table17_02188954 table = data_ov011_02188954;
	func_020c3b64(table.v[idx]);
	return 1;
}
