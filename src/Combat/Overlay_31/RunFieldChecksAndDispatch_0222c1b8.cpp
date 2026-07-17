#include <globaldefs.h>

struct Data02290c8c {
	unsigned char byte0;
	unsigned char pad1[3];
	void* field4;
};

extern struct Data02290c8c data_ov031_02290c8c;
extern int data_ov031_02290c90;

int GetField9AtIndex_0223c054(int);
extern int IsField19ZeroOrNull_02222e54(void);
extern int TailCallForward_0223e2e0(int, void*);
extern "C" void func_ov031_0223da58(int);
extern "C" void func_ov031_0223c760(int);
void ForwardArgsAndNotify_0223b710(int);
extern "C" void func_ov031_0223cbbc(int, int);
void WaitFor8000Then0223cf70_022357b4(void);
extern char* GetOffset400_02235c70(void);
extern "C" void func_ov031_02236094(int);
extern void SetField1014_022274d0(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02233248(void);
void ResetAndInit_02232024(void);
extern void CopyBlockAndClearFlag_02235cac(void*);
extern void SetField181c_0222750c(int, int);
extern "C" void func_ov031_0222cbe0(void);
void Setup022340c0(void);
void FreeAndClearPtr_0223cf70(int);

// USA: func_ov031_0222c1b8
ARM void RunFieldChecksAndDispatch_0222c1b8(void) {
	if (GetField9AtIndex_0223c054(1) != 0) return;
	if (GetField9AtIndex_0223c054(0) != 0) return;
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	TailCallForward_0223e2e0(1, *(void**)((char*)data_ov031_02290c8c.field4 + 0x3c));

	{
		int i = 0;
		do {
			int v1 = *(int*)((char*)data_ov031_02290c8c.field4 + i * 4 + 0x10);
			if (v1) func_ov031_0223da58(v1);
			int v2 = *(int*)((char*)data_ov031_02290c8c.field4 + i * 4 + 0x24);
			if (v2) func_ov031_0223da58(v2);
			i++;
		} while (i < 5);
	}

	func_ov031_0223c760(*(int*)((char*)data_ov031_02290c8c.field4 + 0xc));
	ForwardArgsAndNotify_0223b710(*(int*)((char*)data_ov031_02290c8c.field4 + 4));
	ForwardArgsAndNotify_0223b710(*(int*)((char*)data_ov031_02290c8c.field4 + 8));

	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x1d);

	*(int*)0x4000010 = 0;
	*(int*)0x4000018 = 0;

	{
		char* ctx = (char*)data_ov031_02290c8c.field4;
		if (*(unsigned char*)(ctx + 0x54) == 0) {
			WaitFor8000Then0223cf70_022357b4();
			char* r = GetOffset400_02235c70();
			func_ov031_02236094(*(unsigned char*)(r + 0xf4));
			SetField1014_022274d0(2, 0);
			SetField_022274c0_022274c0((int)func_ov031_02233248);
		} else if (data_ov031_02290c8c.byte0 == 4) {
			WaitFor8000Then0223cf70_022357b4();
			SetField1014_022274d0(0, 1);
			SetField_022274c0_022274c0((int)ResetAndInit_02232024);
		} else {
			unsigned char b52 = *(unsigned char*)(ctx + 0x52);
			char* base3 = *(char**)ctx;
			CopyBlockAndClearFlag_02235cac(base3 + b52 * 0x2a);
			SetField1014_022274d0(0, 0);

			ctx = (char*)data_ov031_02290c8c.field4;
			b52 = *(unsigned char*)(ctx + 0x52);
			base3 = *(char**)ctx;
			if (*(unsigned char*)(base3 + b52 * 0x2a + 0x28) != 0) {
				SetField1014_022274d0(0, 1);
				SetField181c_0222750c(1, 1);
				SetField_022274c0_022274c0((int)func_ov031_0222cbe0);
			} else {
				SetField1014_022274d0(0, 1);
				SetField181c_0222750c(0, 1);
				SetField_022274c0_022274c0((int)Setup022340c0);
			}
		}
	}

	FreeAndClearPtr_0223cf70((int)&data_ov031_02290c90);
}
