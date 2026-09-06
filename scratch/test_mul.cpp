#include <globaldefs.h>
extern "C" int GetSomeInt(void);
extern "C" int func_02030f30(int angle);

// USA: func_ov001_ffffffff
ARM int MulTest_ffffffff(void) {
    int fixedVal = GetSomeInt();
    long long product = fixedVal * 71;
    int wrapped = func_02030f30((int)((product + 0x800) >> 12));
    return wrapped;
}
