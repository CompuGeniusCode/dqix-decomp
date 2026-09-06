#include <globaldefs.h>

struct ListNode_02240628 { ListNode_02240628* next; };
extern "C" ARM void func_ov031_02240410(char* obj, int idx, ListNode_02240628** outNode, int* outRemainder);
extern "C" ARM signed char func_ov031_0224046c(void* obj, void** chain, int* counter);

// USA: func_ov031_02240628
extern "C" ARM int MatchCaseInsensitiveWord02240628(void* obj, int pos, int end, signed char* str, int delim) {
	if (pos >= end) return -1;
	ListNode_02240628* node;
	int rem;
	func_ov031_02240410((char*)obj, pos, &node, &rem);
	int ch = func_ov031_0224046c(obj, (void**)&node, &rem);
	int limit = end - 1;
	for (;;) {
		int sc = *str;
		int fsc = sc;
		if (sc >= 'A' && sc <= 'Z') fsc = sc + 0x20;
		if (ch >= 'A' && ch <= 'Z') ch = ch + 0x20;
		if (ch != fsc) return -1;
		if (sc == 0 || sc == ' ' || sc == delim || pos == limit) return 0;
		ch = func_ov031_0224046c(obj, (void**)&node, &rem);
		pos++;
		str++;
	}
}
