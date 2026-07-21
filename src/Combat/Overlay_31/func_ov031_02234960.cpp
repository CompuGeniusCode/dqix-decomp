#include <globaldefs.h>

extern unsigned char data_ov031_02290ce4;
extern "C" ARM void func_ov031_02234960(void);
extern "C" void func_ov031_02223998(int idx);
extern "C" int func_ov031_02223518(void* obj);
extern "C" void func_020c99c8(void* out);
extern "C" void func_020ca390(int a, void* buf, unsigned int size);
extern "C" int func_020ca3b8(int dst, int src, int size);
extern "C" void func_ov031_02223614(void* buf, int n);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02237448(void* fn);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern "C" ARM void func_ov031_02234cac(void);
extern "C" ARM void func_ov031_02234a08(void);

// USA: func_ov031_022348cc  (semantic: InitAndScheduleTransfer_022348cc)
extern "C" ARM void func_ov031_022348cc(void) {
	unsigned char buf[0x6c];
	data_ov031_02290ce4 = 0;
	func_ov031_02234960();
	func_ov031_02223998(8);
	func_ov031_02223518((void*)2);
	func_020c99c8(&buf[0x16]);
	func_020ca390(0, &buf[0], 0x16);
	unsigned short n = *(unsigned short*)&buf[0x30];
	func_020ca3b8((int)&buf[0x1a], (int)&buf[0], n * 2);
	func_ov031_02223614(&buf[0], 0x28);
	func_ov031_02222b0c(0);
	func_ov031_02237448((void*)func_ov031_02234cac);
	func_ov031_02236878(0xb);
	SetField_022274c0_022274c0((int)func_ov031_02234a08);
}
