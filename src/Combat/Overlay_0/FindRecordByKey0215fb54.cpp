#include <globaldefs.h>

struct Rec0215fb54 { short key; short a; short b; short c; };
struct Out0215fb54 { int x0; int x1; };
extern Rec0215fb54 data_ov000_02182e6c[];

// USA: func_ov000_0215fb54
ARM int FindRecordByKey0215fb54(int unused, short key, Out0215fb54* out) {
    Rec0215fb54* p = data_ov000_02182e6c;
    while (p->key != -1) {
        if (p->key == key) {
            out->x0 = p->a;
            out->x1 = p->b;
            return p->c;
        }
        p++;
    }
    return -1;
}
