#include <globaldefs.h>

struct ListNode_02240410 { ListNode_02240410* next; };
extern "C" ARM void func_ov031_02240410(char* obj, int idx, ListNode_02240410** outNode, int* outRemainder);
extern "C" ARM signed char func_ov031_0224046c(void* obj, void** chain, int* counter);

// USA: func_ov031_022404e8
#pragma optimize_for_size off
extern "C" ARM int FindLineTerminator022404e8(void* obj, int pos, int end, int* errPos) {
	int state = 0;
	if (errPos) *errPos = -1;
	if (pos >= end) goto fail;
	ListNode_02240410* node;
	int rem;
	func_ov031_02240410((char*)obj, pos, &node, &rem);
	if (pos >= end) goto fail;
	do {
		signed char ch = func_ov031_0224046c(obj, (void**)&node, &rem);
		if (ch == ':' && errPos) {
			if (*errPos < 0) *errPos = pos;
		}
		if (state == 0) {
			if (ch == '\r') state = 1;
		} else {
			if (ch == '\n') {
				if (pos == end - 1) return 0;
				return pos + 1;
			}
			state = 0;
		}
		pos++;
	} while (pos < end);
fail:
	return -1;
}
