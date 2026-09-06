#include <globaldefs.h>

struct Stat0215cdf0 { char pad[0x5c]; short cur; short max; };

extern "C" Stat0215cdf0* func_ov004_02156ed0(void* obj, int key);
extern "C" void func_ov004_02158fec(void* obj);

// USA: func_ov004_0215cdf0
ARM int DecrementStat5b_0215cdf0(void* obj) {
    Stat0215cdf0* stat = func_ov004_02156ed0(obj, 0x5b);
    short cur = stat->cur;
    short max = stat->max;
    short newCur = cur - 1;
    if (newCur < 0) newCur = max - 1;
    stat->cur = newCur;
    stat->max = max;
    func_ov004_02158fec(obj);
    return 0;
}
