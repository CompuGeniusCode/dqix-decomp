#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(Struct02030b7c* s);
extern int data_020fdc4c;

// USA: func_0201f634
ARM int CopyStringToBuffer0201f634(Struct02030b7c* s) {
    strcpy(*(char**)((char*)&data_020fdc4c + 0x10) + 0x548, (char*)_ZNK6Script9Parameter8ToStringEv(s));
    return 1;
}
