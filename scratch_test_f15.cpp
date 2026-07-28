#include <globaldefs.h>
#include "std_library_functions.h"
extern char sfx[];
extern "C" int f15(char* battle) {
    char buf0[0x220];
    char* s = battle + 0x5f80;
    unsigned int slen = strlen(s);
    memcpy(buf0, s, slen);
    strcpy(buf0 + slen, sfx);
    return 0;
}
