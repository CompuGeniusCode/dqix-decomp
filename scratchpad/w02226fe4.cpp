#include <globaldefs.h>

extern int data_ov031_02250c0c;
extern "C" int func_ov031_022270ac(int type, unsigned int flags);
int GetDataValue_022167b8(void);
void SetData02249b54_022167a8(int v);
extern "C" void func_ov031_02227128(void);
extern "C" void func_ov031_022271f0(void);
extern "C" void func_ov031_0223677c(void);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_02227d94(void);
ARM void RunTwoStepUpdate_0223d0a4();
extern "C" void func_ov031_0223e168(int);
extern "C" void func_ov031_0223d704(void);
ARM int TryFetchOrDispatch12_0223dfd0(void);
ARM void DelayThenSyncBit0(void);
extern "C" void func_ov031_02227468(void);

extern int data_ov031_0224b608;

// USA: func_ov031_02226fe4
extern "C" ARM int func_ov031_02226fe4(int param0, int param1, int param2) {
	*(int*)((char*)&data_ov031_02250c0c + 0x4) = param0;
	if (func_ov031_022270ac(param1, param2) == 0) {
		return -1;
	}

	int saved = GetDataValue_022167b8();
	SetData02249b54_022167a8((int)&data_ov031_0224b608);
	*(unsigned char*)((char*)&data_ov031_02250c0c + 0x1) = 0;
	func_ov031_02227128();
	func_ov031_022271f0();
	func_ov031_0223677c();
	SetField_022274c0_022274c0((int)func_ov031_02227d94);

	do {
		RunTwoStepUpdate_0223d0a4();
		void (*fn)(void) = *(void (**)(void))((char*)&data_ov031_02250c0c + 0xc);
		fn();
		func_ov031_0223e168(0);
		func_ov031_0223d704();
		TryFetchOrDispatch12_0223dfd0();
		DelayThenSyncBit0();
	} while (*(unsigned char*)((char*)&data_ov031_02250c0c + 0x1) == 0);

	func_ov031_02227468();
	SetData02249b54_022167a8(saved);
	return 0;
}
