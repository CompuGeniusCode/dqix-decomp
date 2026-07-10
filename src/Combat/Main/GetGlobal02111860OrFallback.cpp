#include <globaldefs.h>

ARM int GetGlobal02111860(void);
extern "C" int func_020c9be0(void);

// USA: func_020cff28
ARM int GetGlobal02111860OrFallback(void) {
    int value = GetGlobal02111860();
    if (value != 0) {
        return value;
    }
    return func_020c9be0();
}
