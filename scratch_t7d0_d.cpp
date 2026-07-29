#include <globaldefs.h>
#include "std_library_functions.h"

struct Triple020ca7d0 { int a, b, c; };

// USA: func_020ca7d0
THUMB void ClearNineWords020ca7d0(Triple020ca7d0* obj) {
    memset(&obj[0], 0, sizeof(Triple020ca7d0));
    memset(&obj[1], 0, sizeof(Triple020ca7d0));
    memset(&obj[2], 0, sizeof(Triple020ca7d0));
}
