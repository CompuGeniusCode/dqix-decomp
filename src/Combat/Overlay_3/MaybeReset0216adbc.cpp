#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_ov003_02168324(void* obj);

// USA: func_ov003_0216adbc
ARM void MaybeReset0216adbc(void* obj) {
	if (*(unsigned char*)((char*)obj + 0x5a4) != 0) return;
	int v = (int)BackgroundLoader::GetInstance();
	((BackgroundLoader*)(v))->MaybeFreeAllocations();
	((BackgroundLoader*)(v))->RemoveTask((int)(*(int*)((char*)obj + 0x4e0)));
	*(int*)((char*)obj + 0x4e0) = -1;
	func_ov003_02168324(obj);
	*(unsigned char*)((char*)obj + 0x4ec) = 6;
	*(unsigned char*)((char*)obj + 0x4e8) = 0;
}
