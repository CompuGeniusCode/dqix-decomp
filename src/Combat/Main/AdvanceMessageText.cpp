#include <globaldefs.h>

extern "C" void func_02067e58(void* obj, int count);

// Steps the message printer forward. Every call site traced passes the message work, fourteen of the
// nineteen fetching it from GetMessageWork just before the call and the rest a pointer cached
// earlier. Rendering with func_020439b0 follows at the sites disassembled. The worker behind this
// runs func_02067b28 once per step, which walks the text through FindFontCharEntry, and the step
// count is raised to at least GetFrameTimeStep() so text keeps pace when frames are dropped. This is
// a bare forwarder to func_02067e58; why the callers do not call that directly is not clear.
extern "C" ARM void AdvanceMessageText(void* obj, int count) {
    func_02067e58(obj, count);
}
