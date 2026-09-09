#include <globaldefs.h>

extern "C" void StartMainEngineBrightnessFade(void* obj, int value, int frames);
extern "C" void SetSubScreenBrightness(void* obj, int value, int frames);

// Drives both screens' master brightness at once: StartMainEngineBrightnessFade owns the main engine and SetSubScreenBrightness
// the sub engine, and func_0203b080 later writes their float fields to the MASTER_BRIGHT registers
// 0x400006c and 0x400106c when the matching dirty byte is set. The level is signed, -16 full black
// through +16 full white; a duration of 0 applies it immediately, otherwise it is scaled by 16.667 (one
// frame in milliseconds) into a countdown whose consumer is not identified. func_020db9cc gets first
// refusal on each call and can reject it, so neither half is guaranteed to take effect.
extern "C" ARM void SetBothScreensBrightness(void* obj, int value, int frames) {
    StartMainEngineBrightnessFade(obj, value, frames);
    SetSubScreenBrightness(obj, value, frames);
}
