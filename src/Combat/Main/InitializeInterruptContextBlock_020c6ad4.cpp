#include <globaldefs.h>

struct InterruptContextBlock_027e0060 { int a; int b; };
extern InterruptContextBlock_027e0060 data_027e0060;

// USA: func_020c6ad4
extern "C" ARM void _Z40InitializeInterruptContextBlock_020c6ad4v(void) {
    data_027e0060.b = 0;
    data_027e0060.a = 0;
}
