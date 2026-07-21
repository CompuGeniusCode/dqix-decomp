#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct Obj02206fa4;
int ComputeStatusFlags_02206fa4(struct Obj02206fa4* obj);

struct Elem0220783c {
	void* ptr;
	short half;
	short result;
};

// USA: func_ov031_0220783c
extern "C" ARM int func_ov031_0220783c(struct Elem0220783c* arr, unsigned int count, long long deadline) {
	int hasTimeout = (deadline != -1);
	int matched;
	for (;;) {
		matched = 0;
		struct Elem0220783c* cur = arr;
		unsigned int i = 0;
		if (count > 0) {
			do {
				void* ptr = cur->ptr;
				short half = cur->half;
				int mask = half | 0xE0;
				int result = mask & ComputeStatusFlags_02206fa4((struct Obj02206fa4*)ptr);
				cur->result = (short)result;
				i++;
				if (result != 0) {
					matched++;
				}
				cur++;
			} while (i < count);
		}
		if (matched > 0) {
			break;
		}
		if (hasTimeout) {
			long long neg = -deadline;
			if (neg >= 0) {
				break;
			}
		}
		SleepCurrentContext(1);
		deadline -= 0x20b;
	}
	return matched;
}
