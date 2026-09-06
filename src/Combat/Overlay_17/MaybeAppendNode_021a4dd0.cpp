#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;

extern signed char data_ov017_021d76d8;
extern "C" void func_ov017_021a967c(TailNode020469b4* node);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a4dd0
ARM void MaybeAppendNode_021a4dd0(char* obj) {
	obj += 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(obj + 0x6fc);
	TailNode020469b4* node = *(TailNode020469b4**)(obj + 0xb84);
	if (data_ov017_021d76d8 < 0) {
		return;
	}
	func_ov017_021a967c(node);
	AppendNodeToTail(list, node);
}
