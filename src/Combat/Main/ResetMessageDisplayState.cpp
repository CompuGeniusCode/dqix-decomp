#include <globaldefs.h>
extern "C" void func_02043040(char*);

extern "C" void func_02043124(char* obj);
extern "C" ARM void func_020430b0(char* self);

// Clears the global message context -- the singleton at data_02107800 + 0x1c -- so a new message can
// be built: the 128-entry element table at +0x9b8 with its parallel active flags at +0x17b8, then the
// window state, the current target at +0x1e20 back to +0x914 and the pending index at +0x1838 to -1.
// Same object that carries the 16 name slots at +0x4ac and the bottom-screen text rect
// (0, 0x88)-(0x100, 0xc0). What one of the 128 entries actually is remains open; func_02045c00 only
// shows they are looked up by the id at +0x18 and gated by the active flag.
extern "C" ARM void ResetMessageDisplayState(char* obj) {
    func_02043040((char*)(obj));
    func_02043124(obj);
    func_020430b0(obj);
}
