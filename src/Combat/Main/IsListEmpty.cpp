#include <globaldefs.h>

// Head pointer test for the intrusive list module at 0x02046958-0x02046c78; a null head reads as
// empty. Six of the eleven decompiled callers pass the list at gamemain root +0x36fc, where empty
// presumably means no field state is running, which is why the ov017 proximity and encounter checks
// return early unless this is true. The rest pass other lists -- func_ov017_021b08f4 uses
// base+0x700 and func_ov017_021b2388 base+0x3700 -- and the body only looks at the first pointer,
// so it works on any list head.
extern "C" ARM int IsListEmpty(void** obj) {
    return obj[0] == 0;
}
