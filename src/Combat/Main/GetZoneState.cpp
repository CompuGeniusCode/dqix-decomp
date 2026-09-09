#include <globaldefs.h>

extern int zoneState;

// USA: GetZoneState
extern "C" ARM void* GetZoneState(void) {
    return &zoneState;
}
