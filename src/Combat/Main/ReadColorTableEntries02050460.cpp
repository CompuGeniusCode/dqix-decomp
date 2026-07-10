#include <globaldefs.h>

extern int data_0210791c[];
extern int data_020f030c;

// USA: func_02050460
ARM void ReadColorTableEntries02050460(int *a, int *b, int *c, int *d, int *e) {
    *a = data_0210791c[2];
    *b = data_0210791c[1];
    *c = data_0210791c[0];
    *d = data_0210791c[3];
    *e = data_020f030c;
}
