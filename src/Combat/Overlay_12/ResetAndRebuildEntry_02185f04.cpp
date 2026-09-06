#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void* _Z15GetBattleStructv();

struct List0202fec8;

extern "C" void func_020dfec0(void *a, void *b, int c, int d);

// USA: func_ov012_02185f04
ARM void ResetAndRebuildEntry_02185f04(char *self) {
	_Z15GetBattleStructv();
	int id = (int)BackgroundLoader::GetInstance();
	int field = *(int *)(self + 0x1388);
	int out1, out2;
	((BackgroundLoader*)((List0202fec8 *)id))->GetLoadedFileByID((int)(field), (void**)(&out1), (unsigned int*)(&out2));
	((SafeAllocator *)(self + 0x84))->Reset();
	func_020dfec0(self + 0x1344, self + 0x84, out1, out2);
	((BackgroundLoader*)(id))->RemoveTask((int)(*(int *)(self + 0x1388)));
	*(int *)(self + 0x1388) = -1;
}
