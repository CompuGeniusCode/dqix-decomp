#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void ResetTimersAndBuffers0207e264(unsigned char* self);
extern "C" void func_02034bc4(void* p);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

// USA: func_ov017_0219bc50
ARM void ResetOverlayState_0219bc50(unsigned char* self) {
	ResetTimersAndBuffers0207e264(*(unsigned char**)(self + 0x36c8));
	func_02034bc4(*(void**)(self + 0x36cc));
	((SafeAllocator*)(self + 0xb0))->Reset();
	CopyInternalFields0207df50((struct Foo0207df50*)(self + 0x56c));
}
