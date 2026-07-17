#include <globaldefs.h>

long long GetPair_02212d20(void);
void SetFlagBit0_02211754(struct FlagObj02211754* obj);
extern "C" void func_ov031_02211678(void* dst, int lo, int hi);

struct FlagObj02211754;

// USA: func_ov031_022115d8
ARM void SetField10PairAndFlag_022115d8(void* obj, int value) {
	long long pair = GetPair_02212d20();
	func_ov031_02211678((char*)obj + 0x10, (int)pair, (int)(pair >> 32));
	*(int*)((char*)obj + 0x1c) = value;
	SetFlagBit0_02211754((struct FlagObj02211754*)obj);
}
