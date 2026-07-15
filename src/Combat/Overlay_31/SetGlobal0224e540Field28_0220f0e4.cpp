#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Global0224e540 {
	int pad[10]; /* 0x0-0x24 */
	int field28;
};
extern Global0224e540 data_ov031_0224e540;

// USA: func_ov031_0220f0e4
ARM void SetGlobal0224e540Field28_0220f0e4(int v) {
	unsigned int mask = DisableIRQInterrupts();
	data_ov031_0224e540.field28 = v;
	SetIRQInterruptState(mask);
}
