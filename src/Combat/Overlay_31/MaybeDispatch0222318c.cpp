#include <globaldefs.h>

struct Header_0223bd28;
extern "C" void func_ov031_02222eb0(unsigned int);
extern "C" void func_ov031_0223e2b8(void*, void*);
extern void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern void* data_ov031_02250ba8;
extern "C" void func_ov031_022231f0();

#pragma optimize_for_size off
// USA: func_ov031_0222318c
ARM void MaybeDispatch0222318c(void* arg) {
	unsigned int hi;
	int lo;
	Header_0223bd28* h = *(Header_0223bd28**)((char*)data_ov031_02250ba8 + 8);
	ExtractPackedHiLo_0223bd28(h, 0, &hi, (unsigned int*)&lo);
	lo = lo + 4;
	func_ov031_02222eb0((unsigned int)lo);
	if (lo < 0xc0) return;
	func_ov031_0223e2b8(arg, (void*)func_ov031_022231f0);
}
