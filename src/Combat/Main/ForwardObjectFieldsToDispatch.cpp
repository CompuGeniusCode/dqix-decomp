#include <globaldefs.h>

struct Obj020afe50 {
    int f0;
    int f4;
    int f8;
};

extern "C" int func_020c895c(int, int, int, void *);

// USA: func_020afe50
ARM int ForwardObjectFieldsToDispatch(struct Obj020afe50 *p, int x) {
    return func_020c895c(p->f8, p->f4, x, p);
}
