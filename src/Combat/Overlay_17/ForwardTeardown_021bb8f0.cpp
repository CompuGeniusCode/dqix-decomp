#include <globaldefs.h>

extern "C" void func_ov028_021d9188(void* a);
void BlankFunction0208be90(void);
int IsIndexMappedToSelf020a18f4(unsigned int idx);
extern "C" void func_ov001_0215686c(int a);

// USA: func_ov017_021bb8f0
ARM void ForwardTeardown_021bb8f0(char* p) {
	void* a = *(void**)(p + 0x160);
	if (a != NULL) func_ov028_021d9188(a);
	if (*(void**)(p + 0x120) != NULL) BlankFunction0208be90();
	int r = IsIndexMappedToSelf020a18f4(1);
	if (r == 0) return;
	func_ov001_0215686c(r);
}
