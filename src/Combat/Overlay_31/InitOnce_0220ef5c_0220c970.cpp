#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Timing.h"

ARM void InitOnce_0220ef5c(void);
ARM void SetFieldAt2264_0220d8d4(void);
extern void* data_ov031_0224e53c;

// USA: func_ov031_0220c970
extern "C" ARM int func_ov031_0220c970(unsigned int a, unsigned int b) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224e53c != 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	if (a == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	if (a & 0x1f) {
		SetIRQInterruptState(state);
		return 1;
	}
	if (b < 0x2300) {
		SetIRQInterruptState(state);
		return 6;
	}
	data_ov031_0224e53c = (void*)a;
	*(unsigned int*)((char*)a + 0x2000 + 0x260) = 1;
	*(unsigned short*)((char*)data_ov031_0224e53c + 0x2200 + 0x80) = 0;
	*(unsigned short*)((char*)data_ov031_0224e53c + 0x2200 + 0x68) = 0;
	*(unsigned char*)((char*)data_ov031_0224e53c + 0x2000 + 0x26a) = 0;
	*(unsigned char*)((char*)data_ov031_0224e53c + 0x2000 + 0x26b) = 0;
	*(unsigned short*)((char*)data_ov031_0224e53c + 0x2200 + 0x82) = 0;
	*(unsigned short*)((char*)data_ov031_0224e53c + 0x2200 + 0xf8) = 0;
	SetFieldAt2264_0220d8d4();
	InitOnce_0220ef5c();
	if (!Is64BitTimerInitialized()) Initialize64BitTimer();
	if (!IsAlarmListInitialized()) InitializeActiveAlarmList();
	ZeroInitializeAlarm((Alarm*)((char*)data_ov031_0224e53c + 0x22cc));
	SetIRQInterruptState(state);
	return 0;
}
