#include <globaldefs.h>

struct Stat0215cdac { char pad[0x5c]; short cur; short max; };

extern "C" Stat0215cdac* func_ov004_02156ed0(void* obj, int key);
extern "C" void func_ov004_02158fec(void* obj);

// USA: func_ov004_0215cdac
ARM int IncrementStat5b_0215cdac(void* obj) {
    Stat0215cdac* stat = func_ov004_02156ed0(obj, 0x5b);
    short cur = stat->cur;
    short max = stat->max;
    short newCur = cur + 1;
    if (max <= newCur) newCur = 0;
    stat->cur = newCur;
    stat->max = max;
    func_ov004_02158fec(obj);
    return 0;
}
