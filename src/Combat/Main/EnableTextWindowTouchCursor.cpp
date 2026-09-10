#include <globaldefs.h>

// Sets the byte at +0x94, which turns on the stylus half of a text-window set. That half hangs at
// +0x4: func_0205bc2c reads the point through GetTouchPoint and the press byte at +0x55 of the input
// global data_02114e54, then hit-tests it, and func_0205c570 and func_0205c5b0 consult it only while
// +0x94 is set. +0x95 gates the d-pad grid cursor at +0x54 the same way, which polls IsKeyTriggered.
// func_0205cf10 is the matching clear, and 0x0205cf04/0x0205cf1c do the same pair for +0x95.
extern "C" ARM void EnableTextWindowTouchCursor(void* obj) {
    *(unsigned char*)((char*)obj + 0x94) = 1;
}
