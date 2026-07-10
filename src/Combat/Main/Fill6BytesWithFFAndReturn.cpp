#include <globaldefs.h>

void Fill6BytesWithFF(char* p);

// USA: func_020a1ffc
ARM char* Fill6BytesWithFFAndReturn(char* p) {
    Fill6BytesWithFF(p);
    return p;
}
