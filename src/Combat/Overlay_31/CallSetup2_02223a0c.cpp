#include <globaldefs.h>

extern char* GetOffset400_02235c70(void);
extern void SetupAndCopy_02223998(int);

// USA: func_ov031_02223a0c
ARM void CallSetup2_02223a0c(void) {
	unsigned char* p = (unsigned char*)GetOffset400_02235c70();
	SetupAndCopy_02223998(p[0xf4] + 2);
}
