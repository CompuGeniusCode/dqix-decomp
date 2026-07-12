#include <globaldefs.h>

struct Stopwatch0201fbac;
void UpdateStopwatchState0201fbac(struct Stopwatch0201fbac* t);

struct RawEntry02027288 { char raw[0x14]; };
extern struct RawEntry02027288 data_020fdc60[4];

// USA: func_02027288
ARM void ResetOrFindStopwatch(unsigned char* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            UpdateStopwatchState0201fbac((struct Stopwatch0201fbac*)&data_020fdc60[i]);
        }
        return;
    }
    if (id >= 4) return;
    {
        int i;
        unsigned char* p;
        for (i = 0; i < 4; i++) {
            p = obj + i;
            if (id == p[0x758]) {
                UpdateStopwatchState0201fbac((struct Stopwatch0201fbac*)&data_020fdc60[i]);
                return;
            }
        }
    }
}
