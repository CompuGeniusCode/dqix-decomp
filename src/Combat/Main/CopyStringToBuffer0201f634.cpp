#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02030b7c;
void* GetField4IfField0Zero(Struct02030b7c* s);
extern int data_020fdc4c;

// USA: func_0201f634
ARM int CopyStringToBuffer0201f634(Struct02030b7c* s) {
    strcpy(*(char**)((char*)&data_020fdc4c + 0x10) + 0x548, (char*)GetField4IfField0Zero(s));
    return 1;
}
