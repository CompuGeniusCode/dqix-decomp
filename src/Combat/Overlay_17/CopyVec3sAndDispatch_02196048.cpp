#include <globaldefs.h>

void CopyVec3(int* dst, int* src);
extern "C" void func_020c20d4(int* a, int* b, int* c, void* d);

extern int data_0210a250[3];
extern int data_0210a25c[3];
extern int data_0210a268[3];
extern int data_0210a05c;
struct Field0xfc_02196048 { char pad[0xfc]; int fld; };
extern struct Field0xfc_02196048 data_0210a010;

// USA: func_ov017_02196048
ARM void CopyVec3sAndDispatch_02196048(int* a, int* b, int* c) {
	CopyVec3(data_0210a250, a);
	CopyVec3(data_0210a25c, b);
	CopyVec3(data_0210a268, c);
	func_020c20d4(a, b, c, &data_0210a05c);
	data_0210a010.fld &= ~0xe8;
}
