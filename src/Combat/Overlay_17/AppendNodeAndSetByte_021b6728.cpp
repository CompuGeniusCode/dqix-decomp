#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern "C" void func_ov017_021b6790(void* node);
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b6728  (semantic: AppendNodeAndSetByte_021b6728)
extern "C" ARM void func_ov017_021b6728(char* obj, int mode, unsigned char val) {
	func_ov017_021b6790(*(void**)(obj + 0x3000 + 0xb00));
	AppendNodeToTail((struct TailList020469b4*)*(void**)(obj + 0x3000 + 0x6fc),
	                 (struct TailNode020469b4*)*(void**)(obj + 0x3000 + 0xb00));
	if (mode == 1) {
		((unsigned char*)(*(void**)(obj + 0x3000 + 0xb00)))[0x1f] = 4;
		((unsigned char*)(*(void**)(obj + 0x3000 + 0xb00)))[0x20] = val;
	} else if (mode == 0) {
		((unsigned char*)(*(void**)(obj + 0x3000 + 0xb00)))[0x1f] = 3;
	}
}
