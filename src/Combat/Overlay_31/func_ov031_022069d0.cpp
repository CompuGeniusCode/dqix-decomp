#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_022033e8(void);
void UpdateAndWaitOnContext_02203424(void);
void ZeroField164_02203250(void);
void ClearField164_02203178(void);
extern "C" int func_ov031_022051a8(void* a, void* b);
unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int mask);
struct Node02207108;
void* RemoveFromGlobal0224e22c_02207108(Node02207108* item);
struct Item022070e0;
void PushFrontGlobal0224e230_022070f0(Item022070e0* item);

// USA: func_ov031_022069d0
extern "C" ARM int func_ov031_022069d0(void* p) {
	char* obj = *(char**)((char*)p + 4);
	signed char kind = *(signed char*)(obj + 0x73);
	int match = 1;
	if (kind != 0 && kind != 4) match = 0;
	if (match != 0) {
		AwaitContextCompletion((ProcessorContext*)(*(char**)(obj + 0x68) + 0x20));
		func_ov031_022033e8();
		UpdateAndWaitOnContext_02203424();
		ZeroField164_02203250();
	}
	ClearField164_02203178();
	short flags = *(short*)(obj + 0x70);
	flags &= ~6;
	*(short*)(obj + 0x70) = flags;
	void* ctxArg = (*(signed char*)(obj + 0x73) == 2) ? *(void**)(obj + 0x68) : *(void**)(obj + 0x64);
	func_ov031_022051a8(ctxArg, 0);
	int mask = DisableIRQInterrupts();
	RemoveFromGlobal0224e22c_02207108((Node02207108*)obj);
	PushFrontGlobal0224e230_022070f0((Item022070e0*)obj);
	SetIRQInterruptState(mask);
	*(short*)(obj + 0x70) = *(short*)(obj + 0x70) | 0x20;
	return 0;
}
