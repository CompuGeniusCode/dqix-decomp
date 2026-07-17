#include <globaldefs.h>

typedef void (*FnPtr022234d8)(void*, int, int);
extern void PrepareAndDispatch_022234d8(const unsigned char* name, FnPtr022234d8 fn);
extern "C" void* func_ov031_0223cf4c(int, int);
extern int TransferBg1CharData(int, int, unsigned int);
extern unsigned int GetField8Low4_02227558(void);
extern "C" void func_020c5b98(int, int, int);
extern void* data_ov031_02250bf4;
extern void* data_ov031_0224b3c0;
extern void* data_ov031_0224b410;

// USA: func_ov031_0222390c
ARM void SetupOrTransfer_0222390c(void) {
	data_ov031_02250bf4 = func_ov031_0223cf4c(0xc0, 4);
	PrepareAndDispatch_022234d8((const unsigned char*)&data_ov031_0224b410, (FnPtr022234d8)TransferBg1CharData);
	unsigned int f = GetField8Low4_02227558();
	switch (f) {
	case 0: {
		void* p = ((void**)&data_ov031_0224b3c0)[0];
		PrepareAndDispatch_022234d8((const unsigned char*)p, (FnPtr022234d8)func_020c5b98);
		break;
	}
	case 1: {
		void* p = ((void**)&data_ov031_0224b3c0)[1];
		PrepareAndDispatch_022234d8((const unsigned char*)p, (FnPtr022234d8)func_020c5b98);
		break;
	}
	}
}
