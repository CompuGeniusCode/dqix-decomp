#include <globaldefs.h>

struct ProcessorContext;
int ClampInt020d9808(int* value, int* lo, int* hi);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(ProcessorContext*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

extern int data_020f280c;
extern int data_020f2800;

// USA: _Z22ClampAndSubmit020d97a8iiiiii
ARM int ClampAndSubmit020d97a8(int a, int b, int c, int d, int e, int f) {
    int v = ClampInt020d9808(&d, &data_020f280c, &data_020f2800);
    int ip = v + 0x10;
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj((ProcessorContext*)a, e, f, b + c, c, ip);
    return 1;
}
