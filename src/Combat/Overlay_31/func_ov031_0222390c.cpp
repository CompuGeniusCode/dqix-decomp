#include <globaldefs.h>

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern unsigned int GetField8Low4_02227558(void);
extern "C" int func_020c5b98(int, int, unsigned int);
int TransferBg1CharData(int arg0, int arg1, unsigned int arg2);

extern void* data_ov031_02250bf4;
extern unsigned char data_ov031_0224b410;
extern int data_ov031_0224b3c0[];

// USA: func_ov031_0222390c  (semantic: AllocAndDispatchByField8Low4_0222390c)
extern "C" ARM void func_ov031_0222390c(void) {
	data_ov031_02250bf4 = func_ov031_0223cf4c(0xc0, 4);
	func_ov031_022234d8((int)&data_ov031_0224b410, (Callback_022234d8)TransferBg1CharData);
	unsigned int field = GetField8Low4_02227558();
	switch (field) {
	case 0:
		func_ov031_022234d8(data_ov031_0224b3c0[0], (Callback_022234d8)func_020c5b98);
		break;
	case 1:
		func_ov031_022234d8(data_ov031_0224b3c0[1], (Callback_022234d8)func_020c5b98);
		break;
	}
}
