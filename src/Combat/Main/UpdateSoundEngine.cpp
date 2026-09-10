#include <globaldefs.h>

extern "C" int func_020d22f4(int id);
extern "C" void func_020bc2f0(void);
extern "C" void func_020bed10(void);
extern "C" void func_020d24c4(int a);
extern "C" void func_020bceb4(void);

// Runs one pass of the sound engine: spins until the command queue drains, walks the sound heap's
// allocator list, advances the master volume fade, then the per-player fades for the four players at
// data_02110a4c, and finally re-arms the interrupt state. The fade results index data_020ed82c, the
// NitroSDK decibel table (-32768 at 0, rising to 0 at 127), and the per-player volume is the sum of
// three entries from it. Callers are the BGM open/stop routines around 0x0209c2xx and the setup
// routines of ov015, ov016, ov017, ov019, ov020, ov021 and ov031.
extern "C" ARM void UpdateSoundEngine(void) {
    while (func_020d22f4(0) != 0) {
    }
    func_020bc2f0();
    func_020bceb4();
    func_020bed10();
    func_020d24c4(0);
}
