#include <globaldefs.h>

int IsValuePassedWraparound020d2718(unsigned int x);
extern "C" int func_020d22f4(int);
void WaitUntilChannel7Ready(void);

// USA: func_020d2680
ARM void ProcessQueueUntilValueCommitted020d2680(unsigned int seq) {
    if (IsValuePassedWraparound020d2718(seq)) return;
    while (func_020d22f4(0) != 0) {
    }
    if (IsValuePassedWraparound020d2718(seq)) return;
    WaitUntilChannel7Ready();
    if (IsValuePassedWraparound020d2718(seq)) return;
    do {
        func_020d22f4(1);
    } while (!IsValuePassedWraparound020d2718(seq));
}
