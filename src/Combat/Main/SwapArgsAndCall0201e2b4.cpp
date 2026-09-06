#include <globaldefs.h>
extern "C" int _Z21ExecuteZoneWarpScriptPKvjP12ZoneFeaturesP13SafeAllocator(struct StreamHeader*, int, int, int);


// USA: func_0201e2b4
extern "C" ARM void _ZN12ZoneFeatures14LoadFromScriptEP13SafeAllocatorPKvj(int a, int b, int c, int d) {
    _Z21ExecuteZoneWarpScriptPKvjP12ZoneFeaturesP13SafeAllocator((struct StreamHeader*)(c), (int)(d), (int)(a), (int)(b));
}
