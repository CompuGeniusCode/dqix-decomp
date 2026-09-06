#include <globaldefs.h>

struct Struct02079840 {
    char pad[8];
    int value;
};

// USA: func_02079840
extern "C" ARM int func_02079840(Struct02079840 *obj, char *idx, int dflt) {
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
