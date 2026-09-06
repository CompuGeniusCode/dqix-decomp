#include <globaldefs.h>

extern char* data_ov031_02290cf8;

ARM int CopyToBattleContextBuffer(void* src);
int IssueBattleCommandSlot1(int fn);
int IssueBattleCommandSlot2(int fn);
struct Struct022359e0;
extern "C" void func_ov031_022359e0(struct Struct022359e0* obj);

// USA: func_ov031_022358e8
extern "C" ARM int func_ov031_022358e8(void) {
	data_ov031_02290cf8[0x1e5c] = 1;
	CopyToBattleContextBuffer(data_ov031_02290cf8 + 0x168c);
	if (*(unsigned short*)(data_ov031_02290cf8 + 0x168c) != 2) {
		int r = IssueBattleCommandSlot1((int)func_ov031_022359e0);
		if (r != 2) return 0;
		do {
			CopyToBattleContextBuffer(data_ov031_02290cf8 + 0x168c);
		} while (*(unsigned short*)(data_ov031_02290cf8 + 0x168c) != 2);
	}
	int r2 = IssueBattleCommandSlot2((int)func_ov031_022359e0);
	if (r2 != 2) return 0;
	return 1;
}
