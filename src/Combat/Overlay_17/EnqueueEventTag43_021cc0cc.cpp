#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void* ResetBuffer02052a10(char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc0cc {
	unsigned char tag;
	unsigned char pad0[3];
	signed char field4;
	unsigned char field5;
	char name[12];
	unsigned char pad1[2];
};

// USA: func_ov017_021cc0cc
ARM void EnqueueEventTag43_021cc0cc(void) {
	struct BattleStruct* bs = GetBattleStruct();
	void* search = func_0202ae18();
	void* p = GetData02100044();
	struct CombatantStruct* c = GetCombatantAtField0x3ac(bs);
	if (!c) return;

	LocalEvt021cc0cc buf;
	buf.tag = 0x2b;
	buf.field4 = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
	buf.field5 = 1;
	char* rb = (char*)ResetBuffer02052a10((char*)c);
	strncpy(buf.name, rb, 12);
	func_0205e330(p, &buf, 0);
}
