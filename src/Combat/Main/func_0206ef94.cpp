#include <globaldefs.h>

struct Struct0206ef94 {
    char pad[8];
    int value;
};

// USA: func_0206ef94
extern "C" ARM int func_0206ef94(Struct0206ef94 *obj, char *idx, int dflt) {
    int flag = 1;
    int i = (int)(idx - (char *)0);
    if (i != -1) {
        if (obj->value != 0) {
            flag = 0;
        }
    }
    if (flag == 0) {
        return obj->value + i;
    }
    return dflt;
}
