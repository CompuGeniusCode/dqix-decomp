#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void* obj, int a1, int a2, int a3);
extern "C" void func_ov012_02189af4(void* obj, void* buf, int a2);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufStruct02189a78 { char pad[0x374]; void* buf; };

// USA: func_ov012_02189a78
ARM void SetupBattleTag02189a78(char* base) {
	unsigned char flag = *(unsigned char*)(base + 0x1000 + 0x371);
	func_ov012_021893b4(base, flag, 0xe, 1);

	memset(((struct BufStruct02189a78*)(base + 0x1000))->buf, 0, 0x960);

	func_ov012_02189af4(base, ((struct BufStruct02189a78*)(base + 0x1000))->buf, 0);

	func_0205d304(base + 0xac, ((struct BufStruct02189a78*)(base + 0x1000))->buf, 0, 0, 1, 1, 0, 0);
}
