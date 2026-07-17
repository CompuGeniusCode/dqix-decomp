#include <globaldefs.h>

void* GetFieldPtrByMask_022133f8(unsigned int mask);
extern "C" int GetGlobalFieldcFieldc_022134f0(void);
int GetErrorCodeForCase_022143a8(unsigned int c);
int ReturnErrorNeg6_022143ec(void);
struct EntityStruct022143f4;
int GetFieldbSelect_022143f4(struct EntityStruct022143f4* e);
extern "C" int func_ov031_02214410(void*);

// USA: func_ov031_02214358
ARM int DispatchByGlobalField_02214358(void) {
	void* p = GetFieldPtrByMask_022133f8(1);
	int v = GetGlobalFieldcFieldc_022134f0();
	if (v < 4) {
		return GetErrorCodeForCase_022143a8(v);
	}
	if (v < 5) {
		return ReturnErrorNeg6_022143ec();
	}
	if (v == 5) {
		return GetFieldbSelect_022143f4((struct EntityStruct022143f4*)p);
	}
	return func_ov031_02214410(p);
}
