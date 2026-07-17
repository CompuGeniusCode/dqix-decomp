#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj_021d4a24;
void ClearFields3c_40_44_021d4a24(Obj_021d4a24* obj);
extern "C" void func_ov017_021d4c04(void* a, int b, void* c, int d, void* e, int f);
extern "C" void func_ov001_02164114(void* a);
extern int data_ov001_02165828;

// USA: func_ov001_021538d4
ARM void InitOrClearAllocState_021538d4(int p0, void* unused1, SafeAllocator* alloc) {
	if (p0 == 0 || alloc == 0) {
		ClearFields3c_40_44_021d4a24((Obj_021d4a24*)&data_ov001_02165828);
	} else {
		void* a = alloc->Allocate(0x400);
		void* b = alloc->Allocate(0x1800);
		func_ov017_021d4c04(&data_ov001_02165828, p0, a, 0x80, b, 0x200);
		func_ov001_02164114(&data_ov001_02165828);
	}
}
