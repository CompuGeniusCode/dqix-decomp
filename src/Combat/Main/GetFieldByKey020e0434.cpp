#include <globaldefs.h>

struct Container020e0310;
int LookupFieldByKey020e0440(struct Container020e0310 *c, int key);

// USA: func_020e0434
ARM int GetFieldByKey020e0434(struct Container020e0310 *c, int key) {
    return LookupFieldByKey020e0440(c, key);
}
