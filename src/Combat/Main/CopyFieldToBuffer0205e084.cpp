#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern void* data_02108740[];

// USA: func_0205e084
ARM int CopyFieldToBuffer0205e084(struct Struct02030b7c* s) {
    char* src = (char*)_ZNK6Script9Parameter8ToStringEv(s);
    if (src != NULL) strcpy((char*)data_02108740[1] + 0x1a, src);
    return 1;
}
