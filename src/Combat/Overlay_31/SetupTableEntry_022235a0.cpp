#include <globaldefs.h>

struct ArrBasePair022276b4;
extern "C" int func_ov031_0223c560(int, int);
extern "C" void func_ov031_0223c980(void*, int, int, int, int, int, int, int);
extern int LookupArrayPlusBase_022276b4(ArrBasePair022276b4*, unsigned int);
extern int GetTableEntryByField0_022236d0(void);
extern void SetFlagIfMatchesElem0_0223caec(void*);
extern ArrBasePair022276b4* data_ov031_02290c4c;

// USA: func_ov031_022235a0
ARM void SetupTableEntry_022235a0(unsigned int idx) {
	int handle = func_ov031_0223c560(0, 0);
	int computed = LookupArrayPlusBase_022276b4(data_ov031_02290c4c, idx);
	int tableVal = GetTableEntryByField0_022236d0();
	func_ov031_0223c980((void*)handle, 0xd, 0x28, 0xe6, 0x70, 2, tableVal, computed);
	SetFlagIfMatchesElem0_0223caec((void*)handle);
}
