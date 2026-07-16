#include <globaldefs.h>

extern "C" void func_020c1d60(void* a, void* b, void* c);
void SubmitPendingCommandBlocks(void* r6, void* r5);
void* GetOrInitObject0210a110(void);
extern int data_ov006_02160380[3];
extern int data_ov006_0216038c[3];

struct Obj0215426c {
	char pad0[0x8];
	unsigned int flags8;
	char pad1[0xae - 0xc];
	unsigned char byteAe;
};

// USA: func_ov006_0215426c
ARM void ProcessPendingCommands0215426c(Obj0215426c* o) {
	if (!(o->flags8 & 0x10)) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (data_ov006_02160380[i] == ((o->flags8 & 0x10) ? o->byteAe : -1) && data_ov006_0216038c[i] != 0) {
			SubmitPendingCommandBlocks((void*)data_ov006_0216038c[i], NULL);
			void* obj2 = GetOrInitObject0210a110();
			func_020c1d60((void*)data_ov006_0216038c[i], obj2, (void*)data_ov006_0216038c[i]);
		}
	}
}
