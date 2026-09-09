#include <globaldefs.h>

extern "C" void func_020c99c8(void* out);

struct Struct0200fb08 { unsigned char pad[5]; unsigned char field5; };

// Returns the language the console is set to, clamped to what this build actually ships, and
// stores it at obj+5. The codes are the firmware's own: 0 ja, 1 en, 2 fr, 3 de, 4 it, 5 es, the
// same order as the suffix table at data_020f0da0 that replaces "<LG>" in every asset path.
// Anything but French or Spanish is forced to English, so the de and it members sitting in the gp2
// archives cannot be reached in the USA build - and neither can the German and Italian arms of
// callers like func_ov004_0216a810.
extern "C" ARM unsigned char GetLanguage(Struct0200fb08* obj) {
    unsigned char buf[0x54];
    unsigned char v;
    func_020c99c8(buf);
    v = buf[0];
    obj->field5 = v;
    if (v != 2 && v != 5) obj->field5 = 1;
    return obj->field5;
}
