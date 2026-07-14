#include <globaldefs.h>

struct ProcessorContext;
int ClampInt020d9808(int* value, int* lo, int* hi);
void PopulateContext(ProcessorContext*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

extern int data_020f280c;
extern int data_020f2800;

// USA: func_020d97a8
ARM int ClampAndSubmit020d97a8(int a, int b, int c, int d, int e, int f) {
    int v = ClampInt020d9808(&d, &data_020f280c, &data_020f2800);
    int ip = v + 0x10;
    PopulateContext((ProcessorContext*)a, e, f, b + c, c, ip);
    return 1;
}
