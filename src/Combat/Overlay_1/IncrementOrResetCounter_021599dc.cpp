#include <globaldefs.h>

struct LimitStruct021599dc { char pad[0x10]; int limit; };
struct CounterStruct021599dc { char pad[0x50]; int count; };

// USA: func_ov001_021599dc
ARM int IncrementOrResetCounter_021599dc(LimitStruct021599dc* lim, CounterStruct021599dc* cnt) {
    int cur = cnt->count;
    int max = lim->limit;
    if (cur >= max) {
        cnt->count = 0;
        return 0;
    }
    cnt->count = cur + 1;
    return 1;
}
