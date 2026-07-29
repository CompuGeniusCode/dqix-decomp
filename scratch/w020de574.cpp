#include <globaldefs.h>

struct P020de574 { char pad[4]; int field4; };
struct Obj020de574 { char pad[0x10]; int field10; };

// USA: func_020de574
ARM int SetField4_020de574(struct Obj020de574* obj, struct P020de574* p) {
    int flag = 1;
    int val = p->field4;
    int neg1 = flag - 2;
    int result;
    if (val != neg1) {
        if (obj->field10 != 0) {
            flag = 0;
        }
    }
    if (flag != 0) {
        result = 0;
    } else {
        result = obj->field10 + val;
    }
    p->field4 = result;
    return 1;
}
