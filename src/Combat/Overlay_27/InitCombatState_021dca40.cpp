#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/IPC.h"

struct CombatCtx021dca40 {
	unsigned int field0;
	unsigned int field4;
	unsigned char* field8;
	unsigned char* fieldc;
};

extern CombatCtx021dca40 data_ov027_021e33e0;

void SetCallback_021d8a40(void* cb);
void SetDivRatio_021dd5a4(int val);
void StoreAndClear_021dd5d4(void* obj);
void ResetQueueThenClearFlags_021dadf0(void);
extern "C" void func_020ca390(int val, void* dst, unsigned int size);
extern "C" int func_ov027_021dc96c(void);
extern "C" void func_ov027_021d8c94(void);
extern "C" void func_ov027_021db524(void);
extern "C" void VectorizedMemset(void* dst, int val, int size);

// USA: func_ov027_021dca40  (semantic: InitCombatState_021dca40)
extern "C" ARM int func_ov027_021dca40(int value) {
	int oldIrq = DisableIRQInterrupts();
	*(unsigned short*)(data_ov027_021e33e0.field8 + 0x32) = (unsigned short)value;

	data_ov027_021e33e0.field4 = (unsigned int)(data_ov027_021e33e0.fieldc + 0x7d1f) & ~0x1fu;

	void* savedCallback = *(void**)(data_ov027_021e33e0.fieldc + 0x1000 + 0x4e4);
	func_020ca390(0, data_ov027_021e33e0.fieldc + 0x1340, 0x69c0);
	SetCallback_021d8a40(savedCallback);

	unsigned short soundLen = *(unsigned short*)(data_ov027_021e33e0.field8 + 0x500);
	*(int*)(data_ov027_021e33e0.fieldc + 0x1000 + 0x318) = soundLen - 6;
	unsigned short divArg = *(unsigned short*)(data_ov027_021e33e0.field8 + 0x502);
	SetDivRatio_021dd5a4(divArg);

	StoreAndClear_021dd5d4(data_ov027_021e33e0.fieldc + 0x1538);

	int zero = 0;
	int i = 0;
	do {
		*(int*)(data_ov027_021e33e0.fieldc + 0x1000 + i * 4 + 0x4e8) = zero;
		*(signed char*)(data_ov027_021e33e0.fieldc + 0x1000 + i + 0x526) = -1;
		i++;
	} while (i < 15);
	*(unsigned char*)(data_ov027_021e33e0.fieldc + 0x1000 + 0x524) = zero;

	func_020ca390(0, data_ov027_021e33e0.fieldc + 0x1788, 0x5d40);
	VectorizedMemset(data_ov027_021e33e0.fieldc + 0x1754, 0, 0x1e);

	*(unsigned short*)(data_ov027_021e33e0.field8 + 0x524) = 1;
	*(void(**)(void))(data_ov027_021e33e0.field8 + 0x51c) = func_ov027_021d8c94;
	*(void(**)(void))(data_ov027_021e33e0.field8 + 0x508) = func_ov027_021db524;

	unsigned short v500 = *(unsigned short*)(data_ov027_021e33e0.field8 + 0x500);
	*(unsigned short*)(data_ov027_021e33e0.field8 + 0x34) = v500;
	unsigned short v34 = *(unsigned short*)(data_ov027_021e33e0.field8 + 0x34);
	*(unsigned short*)(data_ov027_021e33e0.field8 + 0x518) = (v34 + 0x23) & ~0x1f;
	unsigned short v502 = *(unsigned short*)(data_ov027_021e33e0.field8 + 0x502);
	*(unsigned short*)(data_ov027_021e33e0.field8 + 0x36) = v502;
	unsigned short v36 = *(unsigned short*)(data_ov027_021e33e0.field8 + 0x36);
	*(unsigned short*)(data_ov027_021e33e0.field8 + 0x51a) = (((v36 + 0xe) * 15 + 0x29) & ~0x1f) << 1;

	ResetQueueThenClearFlags_021dadf0();
	int ret = func_ov027_021dc96c();

	SetIRQInterruptState(oldIrq);

	int ipc = IsIPCCommandHandlerRegistered(0xf, IPCSide_Arm7);
	*(int*)(data_ov027_021e33e0.fieldc + 0x7000 + 0x4c8) = ipc;

	return ret;
}
