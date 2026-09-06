#include <globaldefs.h>

extern char* GetOffset400_02235c70(void);
extern void GetFields181c_02227520(int*, int*);
extern unsigned char data_ov031_02290ca0;

// USA: func_ov031_0222ee34  (semantic: ClearHolderIfFieldZero_0222ee34)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222ee34(void) {
	GetOffset400_02235c70();
	int idx;
	GetFields181c_02227520(NULL, &idx);
	if (idx != 0) return;
	*(unsigned short*)((char*)&data_ov031_02290ca0 + 4) = 0;
	(&data_ov031_02290ca0)[0] = 0;
	(&data_ov031_02290ca0)[2] = 0;
}
