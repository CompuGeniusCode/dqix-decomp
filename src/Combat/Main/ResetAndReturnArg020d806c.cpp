#include <globaldefs.h>

struct ResetObj020d7a5c;
void ResetAndClearFlags020d7a5c(struct ResetObj020d7a5c* o);

// USA: func_020d806c
ARM struct ResetObj020d7a5c* ResetAndReturnArg020d806c(struct ResetObj020d7a5c* obj) {
    ResetAndClearFlags020d7a5c(obj);
    return obj;
}
