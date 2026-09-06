#include <globaldefs.h>

struct TrackerState {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    char unk18[0x20];
    unsigned char unk38;
};

// USA: func_0201f01c
ARM void ResetTrackerState(struct TrackerState* state) {
    state->unk0 = 0;
    state->unk4 = 0;
    state->unk8 = 0;
    state->unkC = 0;
    state->unk10 = 0;
    state->unk14 = 0;
    state->unk38 = 0;
}
