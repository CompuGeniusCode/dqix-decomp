#include <globaldefs.h>
typedef int (*Getter020e2cc4)();
typedef void (*Setter020e2cc4)(int);
extern Getter020e2cc4 data_020f2bdc[];
extern Setter020e2cc4 data_020f2bec[];
struct Entry020e2cc4 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
};
// USA: func_020e2cc4
ARM void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled) {
    int v;
    if (obj->state == enabled) return;
    obj->state = enabled;
    v = data_020f2bdc[obj->type]();
    if (enabled) v |= 1 << obj->subtype;
    else v &= ~(1 << obj->subtype);
    data_020f2bec[obj->type](v);
}
