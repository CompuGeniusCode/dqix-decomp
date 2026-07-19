#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern "C" int func_ov031_02214410(void*);

struct EntityStruct022143f4 { unsigned char pad[0xb]; unsigned char fieldb; };

int GetErrorCodeForCase_022143a8(unsigned int c);
int ReturnErrorNeg6_022143ec(void);
int GetFieldbSelect_022143f4(struct EntityStruct022143f4* e);
void* GetGlobalFieldcFieldc_022134f0(void);

// USA: func_ov031_02214358  (semantic: DispatchByGlobalCase_02214358)
extern "C" ARM int func_ov031_02214358(void) {
	char* entity = func_ov031_022133f8(1);
	int val = (int)GetGlobalFieldcFieldc_022134f0();
	if (val < 4) return GetErrorCodeForCase_022143a8(val);
	if (val < 5) return ReturnErrorNeg6_022143ec();
	if (val == 5) return GetFieldbSelect_022143f4((struct EntityStruct022143f4*)entity);
	return func_ov031_02214410(entity);
}
