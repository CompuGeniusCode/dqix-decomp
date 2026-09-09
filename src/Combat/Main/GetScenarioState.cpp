#include <globaldefs.h>

extern int data_02108844;

// Returns the game's global scenario record; only six functions name the global directly, and 184
// call this. func_0206461c formats data/scenario/trigger<zone>.bin -- 76 exist, one per zone code,
// the one-letter triggerF.bin special-cased -- and func_02064574 runs the loaded file through the
// Script VM with this record as its subject. Most callers only want the flag bits at +0x8c, but the
// record also holds a list head at +0x47c and an id and time pair at +0x484..+0x48c that gate
// script-registered trigger entries, so "scenario" seems narrower than the object's real role.
extern "C" ARM void* GetScenarioState(void) {
    return &data_02108844;
}
