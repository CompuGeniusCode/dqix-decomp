#include <globaldefs.h>

extern void Reset0208e4bc(char* obj);

// USA: func_0208e870
ARM char* ResetAndReturnSelf0208e870(char* obj) {
    Reset0208e4bc(obj);
    return obj;
}
