#include <globaldefs.h>

struct Triple020ca7d0 {
    unsigned int a, b, c;
};

// USA: func_020ca7d0
THUMB void ClearNineWords020ca7d0(Triple020ca7d0* obj) {
    obj->a = 0; obj->b = 0; obj->c = 0; obj++;
    obj->a = 0; obj->b = 0; obj->c = 0; obj++;
    obj->a = 0; obj->b = 0; obj->c = 0;
}
