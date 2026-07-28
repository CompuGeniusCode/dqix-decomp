#include <globaldefs.h>

struct ListNode_02240410 { void* next; };
extern "C" void func_ov031_02240410(void* obj, int idx, ListNode_02240410** outNode, int* outRemainder);
extern "C" signed char func_ov031_0224046c(void* obj, void** chain, int* counter);

// USA: func_ov031_022404e8  (semantic: FindColonThenLine_022404e8)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022404e8(void* obj, int start, int end, int* outPtr) {
	int inQuote = 0;
	if (outPtr) {
		*outPtr = -1;
	}
	if (start >= end) {
		goto fail;
	}
	ListNode_02240410* node;
	int rem;
	func_ov031_02240410(obj, start, &node, &rem);
	if (start >= end) {
		goto fail;
	}
	int i = start;
	do {
		signed char c = func_ov031_0224046c(obj, (void**)&node, &rem);
		if (c == ':' && outPtr && *outPtr < 0) {
			*outPtr = i;
		}
		if (!inQuote) {
			if (c == '\r') {
				inQuote = 1;
			}
		} else {
			if (c == '\n') {
				return (i == end - 1) ? 0 : i + 1;
			}
			inQuote = 0;
		}
		i++;
	} while (i < end);
fail:
	return -1;
}
