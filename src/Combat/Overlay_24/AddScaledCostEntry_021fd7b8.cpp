#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct AddEntryList_021f6a1c;
void AddEntryIfUnderLimit16_021f6a1c(struct AddEntryList_021f6a1c* obj, void* src);

struct Inner12_021fd7b8 { unsigned int w[3]; };

// USA: func_ov024_021fd7b8  (semantic: AddScaledCostEntry_021fd7b8)
extern "C" ARM void func_ov024_021fd7b8(void* objRaw) {
	char* obj = (char*)objRaw;
	float scale = 12.5f;
	struct CombatantStruct* c668 = *(struct CombatantStruct**)(obj + 0x668);
	int byteVal48 = *(unsigned char*)((char*)c668->currentStats + 0x48);
	float scaled1 = scale * ((float)byteVal48 / 100.0f);
	struct Inner12_021fd7b8 local = *(struct Inner12_021fd7b8*)(obj + 0x65c);
	short v = *(short*)(*(char**)(obj + 0x64c) + 0x32);
	*(float*)&local.w[0] = (float)v;
	unsigned char pctBase = ((unsigned char*)&local)[7];
	float ratio2 = (float)pctBase * scaled1 / 100.0f;
	((unsigned char*)&local)[7] = (unsigned char)(int)ratio2;
	((unsigned char*)&local)[8] = 2;
	AddEntryIfUnderLimit16_021f6a1c(*(struct AddEntryList_021f6a1c**)(obj + 0x658), &local);
}
