#include <globaldefs.h>

struct LimitStruct0215996c { char pad[0x10]; int limit; };
struct CounterStruct0215996c { char pad[0x60]; int count; };

// USA: func_ov001_0215996c
ARM int IncrementOrResetCounter_0215996c(LimitStruct0215996c* lim, CounterStruct0215996c* cnt) {
	int cur = cnt->count;
	int max = lim->limit;
	if (cur >= max) {
		cnt->count = 0;
		return 0;
	}
	cnt->count = cur + 1;
	return 1;
}
