#include <globaldefs.h>

struct TailNode020469b4 { unsigned char pad0[2]; unsigned char inList; unsigned char pad3; void* next; };
struct TailList020469b4 { void* head; void* tail; };
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_0219bc88
ARM void AppendNodeIfNotInList_0219bc88(unsigned char* base, void* unused1) {
	base += 0x3000;
	TailNode020469b4* node = *(TailNode020469b4**)(base + 0xbb4);
	if (node->inList == 0) {
		TailList020469b4* list = *(TailList020469b4**)(base + 0x6fc);
		AppendNodeToTail(list, node);
	}
}
