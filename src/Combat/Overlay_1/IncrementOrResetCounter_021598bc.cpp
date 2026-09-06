#include <globaldefs.h>

struct LimitStruct021598bc { char pad[0x10]; int limit; };
struct CounterStruct021598bc { char pad[0x64]; int count; };

// USA: func_ov001_021598bc
ARM int IncrementOrResetCounter_021598bc(LimitStruct021598bc* lim, CounterStruct021598bc* cnt) {
	int cur = cnt->count;
	int max = lim->limit;
	if (cur >= max) {
		cnt->count = 0;
		return 0;
	}
	cnt->count = cur + 1;
	return 1;
}
