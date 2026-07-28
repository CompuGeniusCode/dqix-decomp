#include <globaldefs.h>

#pragma optimize_for_size off

extern int data_ov031_0224e6e0;

// USA: func_ov031_0221d060  (semantic: SetGlobalField10_0221d060)
extern "C" THUMB void func_ov031_0221d060(int value) {
    *(int*)((char*)&data_ov031_0224e6e0 + 0x10) = value;
}
