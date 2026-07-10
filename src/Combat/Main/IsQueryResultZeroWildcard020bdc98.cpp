#include <globaldefs.h>

extern "C" int func_020bddec(void* obj, int a, int b, int c, int d);

// USA: func_020bdc98
ARM int IsQueryResultZeroWildcard020bdc98(void* obj, int arg) {
    return func_020bddec(obj, 0xff, arg, 1, 0) == 0;
}
