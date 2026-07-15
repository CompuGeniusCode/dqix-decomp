#include <globaldefs.h>

struct LimitStruct02158470 { char pad[0x1c]; int limit; };
struct CounterStruct02158470 { char pad[0x44]; int count; };

// USA: func_ov001_02158470
ARM int IncrementOrResetCounter_02158470(LimitStruct02158470* lim, CounterStruct02158470* cnt) {
	int cur = cnt->count;
	int max = lim->limit;
	if (cur >= max) {
		cnt->count = 0;
		return 0;
	}
	cnt->count = cur + 1;
	return 1;
}
