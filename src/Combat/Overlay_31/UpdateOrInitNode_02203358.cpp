#include <globaldefs.h>

extern "C" int InitOrValidate_0220a540(void* self);
extern "C" int func_ov031_022032a4(void* self);

struct RootStruct_02203358 {
	char pad[4];
	void* field4;
};

extern RootStruct_02203358 data_02111304;

#pragma optimize_for_size off
// USA: func_ov031_02203358
ARM int UpdateOrInitNode_02203358(void) {
	void* node = *(void**)((char*)data_02111304.field4 + 0xa4);
	if (node != NULL) {
		if (*((unsigned char*)node + 9) != 0) {
			return InitOrValidate_0220a540(node);
		}
		return func_ov031_022032a4(node);
	}
	return 1;
}
