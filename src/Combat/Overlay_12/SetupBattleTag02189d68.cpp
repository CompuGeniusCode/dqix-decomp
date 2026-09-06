#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void* obj, int a1, int a2, int a3);
extern "C" void func_ov012_02189dfc(void* obj, void* buf, int a2);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufStruct02189d68 { char pad[0x374]; void* buf; };

// USA: func_ov012_02189d68
ARM void SetupBattleTag02189d68(char* base) {
	unsigned char flag = *(unsigned char*)(base + 0x1000 + 0x371);
	func_ov012_021893b4(base, flag, 0x10, 1);

	memset(((struct BufStruct02189d68*)(base + 0x1000))->buf, 0, 0x960);

	func_ov012_02189dfc(base, ((struct BufStruct02189d68*)(base + 0x1000))->buf, 0);

	unsigned short raw = *(unsigned short*)(base + 0x1300 + 0xc4);
	unsigned int t = (unsigned int)raw << 27;
	t = t >> 27;
	int flag2 = 0;
	if (t > 9) flag2 = 1;

	func_0205d304(base + 0xac, ((struct BufStruct02189d68*)(base + 0x1000))->buf, 0, 0, flag2, 1, 0, 0);
}
