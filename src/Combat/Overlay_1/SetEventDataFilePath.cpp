#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d612c(void* obj);
extern char strDataStr_02165745;

// Event script command 0x238 - the ov001 handler table pairs that id with this address at
// 0x02165538. It formats "data/<name>" from the command's string operand into the 28-byte character
// field at 0xd8 of the event resource block hanging off gamemain+0x3734. Command 0x236 next door
// appends "data/<name>" nodes to the list at 0xd4 of the same block, and func_ov001_02155bb8 waits
// on both node lists and on the loader task id at 0xf4, just past this field, so 0xd8 seems to be
// one more file for the block to fetch. No reader of the field itself has been found.
extern "C" ARM int SetEventDataFilePath(void* obj) {
    char* base = func_ov017_0218b5b0();
    char* p = *(char**)(base + 0x3000 + 0x734);
    int v = func_ov017_021d612c(obj);
    sprintf(p + 0xd8, &strDataStr_02165745, v);
    return 1;
}
