#include <globaldefs.h>

// USA: func_020d9808
ARM int ClampInt020d9808(int* value, int* lo, int* hi) {
    int mn = *lo;
    int v = *value;
    if (v <= mn) {
        v = mn;
    }
    if (v >= *hi) {
        v = *hi;
    }
    return v;
}
