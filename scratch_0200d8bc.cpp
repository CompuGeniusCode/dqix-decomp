#include <globaldefs.h>

__swi(0x123456) void SemihostCall0200d8bc(int reason, int arg);

// USA: func_0200d8bc
ARM void ReportException0200d8bc(void) {
    SemihostCall0200d8bc(0x18, 0);
}
